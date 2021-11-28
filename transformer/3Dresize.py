from scipy.io import loadmat,savemat
import numpy as np
from scipy.ndimage.interpolation import zoom
for i in range(1,29):
    grain = loadmat('D:/SandSimulationToolbox-master/sandsim_outputs/1000scaler/grain'+str(i)+'.mat')
    grain_array = np.array(grain['grain'])
    grain_shape = grain_array.shape
    shape1 = np.array([80,80,80])
    shape2 = np.array([150,150,150])
    shape3 = np.array([200,200,200])
    factor1 = shape1/grain_shape
    factor2 = shape2/grain_shape
    factor3 = shape3/grain_shape
    grain_array1 = zoom(grain_array, factor1, order=0,mode = 'nearest')
    grain['grain'] = grain_array1
    savemat('grains/grain'+str(3*(i-1)+1)+'.mat',grain)
    grain_array2 = zoom(grain_array, factor2, order=0,mode = 'nearest')
    grain['grain'] = grain_array2
    savemat('grains/grain'+str(3*(i-1)+2)+'.mat',grain)
    grain_array3 = zoom(grain_array, factor3, order=0,mode = 'nearest')
    grain['grain'] = grain_array3
    savemat('grains/grain'+str(3*(i-1)+3)+'.mat',grain)
    # print(grain_array1.shape)
    # print(np.unique(grain_array1))
