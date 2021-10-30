# import numpy as np
# from math import sqrt
# def choleskyDecomposition(a):
#   a = np.array(a, float)
#   L = np.zeros_like(a)
#   n,_ = np.shape(a)
#   for j in range(n):
#     for i in range(j, n):
#       if i == j:
#         sum = 0
#         for k in range(j):
#           sum += L[i, j]**2
#         L[i, j] = sqrt(a[i, j] - sum)
#       else:
#         sum = 0
#         for k in range(j):
#           sum += L[i, k] * L[j, k]
#         L[i, j] = (a[i, j] - sum) / L[j, j]
#   return L

# def check(a): 
#   flag = True
#   v = np.linalg.eigvals(a)
#   n,_ = np.shape(a)
#   for value in v:
#     if(value < 0):
#       flag = False
#   for i in range(n):
#     for j in range(n):
#       if(a[i, j] != a[j, i]):
#         flag = False
#   return flag


# if __name__ == '__main__':
#   a = np.array([[7.3, 1, 0], [1, 20, 3.5], [0, 3.5, 2]])
#   if check(a) == True:
#     L = choleskyDecomposition(a)
#     print("Matrix L: \n" + str(L))
#   else: 
#     print("Error !!!")

  
  