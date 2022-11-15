"""
Discrete -time system
"""
import numpy as np
import matplotlib . pyplot as plt
N = 100 # number of samples
y = np.zeros ((1,N), float )
u = np.ones ((1,N), float) # Step input
x = np.zeros ((3,N+1) , float )
A = np.array ([[0.9004 , 0.0402 , -0.0997] ,
    [ -0.0312 , 0.9207 , 0.1494] ,
    [0.0586 , 0.0882 , 0.8226]])
B = np.array ([[0.0048] , [0.0565] , [0.1021]])
C = np.array ([[1. , 0., 0.]])
for k in np. arange (N):
    x[:,[k+1]] = np. matmul (A,x[:,[k]]) + B*u[:,k]
    y[:,k] = np. matmul (C,x[:,k])
# Plot the results
plt.plot(np. arange (N), x[0 ,0:100] , 'b.',label='x_1 ')
plt.plot(np. arange (N), x[1 ,0:100] , 'r.',label='x_2 ')
plt.plot(np. arange (N), x[2 ,0:100] , 'k.',label='x_3 ')
plt. legend ()
plt. xlabel ('k')
plt. ylabel ('x[k]')
plt.grid ()
plt.show ()
