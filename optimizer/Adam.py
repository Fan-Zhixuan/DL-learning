import numpy as np

class Adam(object):
    def __init__(self, lr=1e-3, alpha=0.9, beta=0.999, eps=1e-8):
        self.s = 0
        self.r = eps
        self.lr = lr
        self.alpha = alpha
        self.beta = beta
        self.alpha_i = 1
        self.beta_i = 1

    def update(self, g: np.ndarray):
        self.s = self.s * self.alpha + (1-self.alpha) * g
        self.r = self.r * self.beta + (1-self.beta) * np.square(g)
        self.alpha_i *= self.alpha
        self.beta_i *= self.beta_i
        lr = -self.lr * (1-self.beta_i)**0.5 / (1-self.alpha_i)
        return lr * self.s / np.sqrt(self.r)