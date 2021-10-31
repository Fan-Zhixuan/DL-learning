import numpy as np

class Momentum(object):
    def __init__(self,alpha,lr=1e-3):
        self.alpha = alpha  # 动量系数
        self.lr = lr        # 学习率
        self.v = 0          # 初始速度为0

    def update(self, g: np.ndarray):    # g = J'(w) 为本轮训练参数的梯度
        self.v = self.alpha * self.v - self.lr * g  # 指数衰减公式
        # self.v = self.lr * (self.alpha * self.v + (1 - self.alpha) * g) #加权平均衰减公式 
        return self.v    # 返回的是参数的增量


optimizer = Momentum(alpha=0.5)
