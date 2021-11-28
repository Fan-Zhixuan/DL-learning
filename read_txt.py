import cv2
from PIL import Image
import numpy as np
# im=Image.open("1.jpg")
# # im = cv2.imread('1.jpg',cv2.IMREAD_UNCHANGED)

# im = np.array(im)
# print(im.shape)

dirpath = '1.jpg'
import skimage.io as io
img_io = io.imread(dirpath)#读取数据
 
 
print("img_io :",img_io .shape)
# img_io : (1856, 2736, 3)
 
 
print("img_io :",type(img_io ))
# img_io : <class 'numpy.ndarray'
cv2.imshow('img',img_io)
cv2.waitKey(0)