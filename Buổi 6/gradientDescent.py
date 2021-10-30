# Ứng dụng của thuật toán: Gradient Descent in TensorFlow
import numpy as np  
import matplotlib.pyplot as plt 
from functions import *
raw = np.loadtxt(data.txt, delimiter = ',')
X = np.copy(raw)
X[:,1] = X[:,0]
X[:,0] = 1
y = raw[:,1]
[Theta, J_hist] = GradientDescent(X,y) 
predict = predict(X,Theta) * 10000
#Plot kết quả
plt.figure(1)
plt.plot(X[:,1],y,’rx’)
plt.plot(X[:,1],predict/10000,’-b’) 
plt.figure(2)
plt.plot(J_hist[:,0],J_hist[:,1],’-r’)
plt.show()

def printProgressBar (iteration, total, suffix = ''):
    percent = ("{0:." + str(1) + "f}").format(100 * ((iteration+1) / float(total)))
    filledLength = int(50 * iteration // total)
    bar = '=' * filledLength + '-' * (length - filledLength)
    print('\rTraining: |%s| %s%%' % (bar, percent), end = '\r')
    # Print New Line on Complete
    if iteration == total: 
        print()

def GradientDescent(X,y,alpha=0.02,iter=5000): 
    theta = np.zeros(np.size(X,1))  
    J_hist = np.zeros((iter,2)) 
    m = np.size(y)
    X_T = np.transpose(X)
    pre_cost = computeCost(X,y,theta)
    for i in range(0,iter):
        printProgressBar(i,iter)
        error = predict(X,theta) – y
        theta = theta – (alpha/m)*(X_T @ error)
        cost = computeCost(X,y,theta)
        if np.round(cost,15) == np.round(pre_cost,15):
            print(‘Reach optima at I = %d ; J = %.6f’%(i,cost))
            J_hist[i:,0] = range(i,iter)
            J_hist[i:,1] = cost
            break
        pre_cost = cost
        J_hist[i, 0] = i
        J_hist[i, 1] = cost
    yield theta
    yield J_hist