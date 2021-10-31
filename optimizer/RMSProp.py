import numpy as np

class RMSProp(object):
    def __init__(self, lr=1e-3, beta=0.999, eps=1e-8):
        self.r = eps  ##防止除0的增加项
        self.lr = lr
        self.beta = beta

    def update(self, g: np.ndarray):
        self.r = self.r * self.beta + (1-self.beta) * np.square(g)
        return -self.lr * g / np.sqrt(self.r)