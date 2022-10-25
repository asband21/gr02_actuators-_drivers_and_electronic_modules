import numpy as np
import matplotlib.pyplot as plt

def ref_fun(x):
    return 1/(x*x-x+1)

dt = 0.01
t = np.arange(-15, 15, dt)
nse1 = np.random.randn(len(t))                 # white noise 1
nse2 = np.random.randn(len(t))                 # white noise 2

for i in range(len(t)):
    nse1[i] = ref_fun(t[i])
    nse2[i] = ref_fun(t[i])

s1 = nse1 
s2 = nse2 

fig, axs = plt.subplots(2, 1)
axs[0].plot(t, s1, t, s2)
axs[0].set_xlim(-15, 15)
axs[0].set_xlabel('time')
axs[0].set_ylabel('s1 and s2')
axs[0].grid(True)

cxy, f = axs[1].cohere(s1, s2, 256, 1. / dt)
axs[1].set_ylabel('coherence')

fig.tight_layout()
plt.show()
