import numpy as np
from math import sqrt
    
def findU(A): 
  tran = np.dot(A, np.transpose(A))
  w, v = np.linalg.eig(tran) #left singular vector  
  return v

def findD(A): 
  m, n = np.shape(A)
  D = np.zeros((m, n))
  tran = np.dot(A, np.transpose(A))
  rank = np.linalg.matrix_rank(A) 
  v = np.linalg.eigvals(tran) 
  for i in range(rank):
    D[i, i] = sqrt(v[i])
  return D

def findVT(A): 
  tran = np.dot(np.transpose(A), A)
  w, v = np.linalg.eig(tran) #right singular vector
  return np.transpose(v)

if __name__ == '__main__':
  m, n = 5,4
  A = np.random.rand(m, n)
  print("A: \n" + str(A))
  U = findU(A)
  D = findD(A)
  VT = findVT(A)
  print("U: \n" + str(U))
  print("D: \n" + str(D))
  print("V^T: \n" + str(VT))
  # left = np.dot(U, D)
  # all = np.dot(left, VT)
  # print("A = U*D*V^T = \n" + str(all))



# import numpy as np

# from numpy import linalg as LA

# if __name__ == '__main__':

#   m, n = 5,4

#   # A = np.random.rand(m, n)
#   A = np.array([[3, 2, 5], [7, 2, 8], [2, 6, 2]])
#   U, S, V = LA.svd(A)
#   # left = np.dot(U, S)
#   # all1 = np.dot(left, V)

#   print('----- Matrix A: -----\n' + str(A) + '\n')

#   print('----- Matrix U: -----\n' + str(U) + '\n')

#   print('----- Matrix S: -----\n' + str(S) + '\n')

#   print('----- Matrix V: -----\n' + str(V) + '\n')

#   # print("A = U*D*V^T = \n" + str(all1))
