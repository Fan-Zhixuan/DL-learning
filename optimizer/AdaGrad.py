import numpy as np

class AdaGrad(object):
    def __init__(self, eps=1e-8, lr=1e-3):
        self.r = eps    # r_0 = epsilon
        self.lr = lr

    def update(self, g: np.ndarray):
        self.r = self.r + np.square(g)
        return -self.lr * g / np.sqrt(self.r)

optimizer = AdaGrad()
g = np.array([1,2,3,4])
w = np.array([1,2,3,4])
for i in range(10):
    print(i)
    w = w + optimizer.update(g)
    print(optimizer.update(g))