import numpy as np
import torch.nn as nn


class SGD(object):
    def __init__(self,lr=1e-3):
        self.lr = lr

    def update(self,g):
        deltaw = -self.lr*g
        return deltaw