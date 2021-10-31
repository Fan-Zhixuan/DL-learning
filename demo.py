import random
import math

import cv2
import numpy as np
from PIL import Image
from transformer.transform import *


im = cv2.imread('transformer/img.png',cv2.IMREAD_UNCHANGED)
label = cv2.imread('transformer/label.png',cv2.IMREAD_UNCHANGED)
def transform(im,label,
              trans = [RandomHorizontalFlip(prob=0.5),
                       RandomVerticalFlip(prob=0.1),
                       Resize(target_size=(512, 512), interp='LINEAR'),
                       Normalize(mean=(0.5, 0.5, 0.5), std=(0.5, 0.5, 0.5)),
                       ResizeStepScaling(min_scale_factor=0.75,max_scale_factor=1.25,scale_step_size=0.25),
                       RandomNoise(prob=0.5, max_sigma=10.0),
                       RandomBlur(prob=0.1, blur_type="gaussian"),
                       RandomRotation(max_rotation=15,im_padding_value=(127.5, 127.5, 127.5),label_padding_value=255),
                       RandomDistort(brightness_range=0.5,brightness_prob=0.5,contrast_range=0.5,contrast_prob=0.5,saturation_range=0.5,
                                     saturation_prob=0.5,hue_range=18,hue_prob=0.5,sharpness_range=0.5,sharpness_prob=0),
                       RandomPaddingCrop(crop_size=(256, 256),im_padding_value=(127.5, 127.5, 127.5),label_padding_value=255)]):
    for tran in trans:
        model = tran
        im,label = model(im,label)
    return im,label
cv2.imwrite('transformer/label1.png',label)
cv2.imwrite('transformer/im1.png',im) 