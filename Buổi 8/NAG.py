    #NAG
import math
import numpy as np
import matplotlib.pyplot as plt
alpha = 0.1
beta = 0.9

def func(x):
	return x*x + 10* math.sin(x)
def grad_func(x):
	return 2*x +10*math.cos(x)
theta_0 = 0
v_t = 0 
t = 0
theta_list = []
while (1):
    t+=1
    v_t =v_t * beta  +  0.01 *(grad_func(theta_0 - beta*v_t))
    theta_0_prev = theta_0								
    theta_0 = theta_0 - v_t
    theta_list.append(theta_0)
    if(theta_0 == theta_0_prev):		#checks if it is converged or not
        break
Set_test = np.arange(len(theta_list),dtype='i')
plt.plot(theta_list)
plt.show()