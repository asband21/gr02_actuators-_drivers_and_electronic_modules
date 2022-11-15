import numpy as np
import matplotlib.pyplot as plt

class pid:
    def __init__(self, kp, kd, ki):
        self.kp = kp
        self.kd = kd
        self.ki = ki
        self.error = 0
        self.gl_error = 0
        self.tid = 0
        self.gl_tid = 0
        self.p = 0
        self.d = 0
        self.i = 0
        self.val = 0
        self.rek_val = 0
        self.del_tid = 0
    def fin_error(self, val, rek_val):
        self.gl_error = self.error
        error = (val - rek_val)
    def fin_del_tid(self):
        self.del_tid =(self.tid-self.gl_tid)
    def fin_p(self):
        self.p = self.error
    def fin_i(self):
        self.i = self.error*self.del_tid + self.i
    def fin_d(self):
        self.d = (self.error-self.gl_error)/(self.del_tid)
    def update(self, tid, val):
        self.gl_tid = self.tid
        self.tid = tid
        self.fin_error(self.val, val)
        self.fin_del_tid()
        self.fin_i()
        self.fin_d()
        self.fin_p()
        print(f"val:{self.val} error:{self.error} t:{self.tid} i:{self.i} p:{self.p} d{self.d}")
        self.val = self.i*self.ki + self.d*self.kd + self.p*self.kp
        return self.val


def ref_fun(x):
    return 1/(x*x-x+1)


######### ploter ###########3
dt = 0.05
t = np.arange(-15, 15, dt)
nse1 = np.random.randn(len(t))
nse2 = np.random.randn(len(t))

pid_ob = pid(35,20,10)
for i in range(len(t)):
    nse1[i] = ref_fun(t[i])
    #print(nse1[i])
    nse2[i] = pid_ob.update(t[i],nse1[i])

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
