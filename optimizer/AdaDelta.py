import numpy as np

class AdaDelta(object):
    def __init__(self, beta=0.999, eps=1e-8):
        self.r = eps
        self.s = eps
        self.beta = beta

    def update(self, g: np.ndarray):
        g_square = (1-self.beta) * np.square(g)     # (1-beta)*g^2
        self.r = self.r * self.beta + g_square      # beta*ri-1+(1-beta)*g^2
        frac = self.s / self.r                      
        res = -np.sqrt(frac) * g                    #deltaw
        self.s = self.s * self.beta + np.square(res) * (1 - self.beta)      # beta*si-1+(1-beta)*deltaw^2
        return res