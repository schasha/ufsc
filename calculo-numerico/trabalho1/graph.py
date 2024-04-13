import matplotlib.pyplot as plt
import numpy as np

def f(x):
    return x**4 - 3*x**3 + x**2 + x + 1

a = -1.5
b = 1.5
plt.figure(1)
x = np.linspace(a,b,50)
plt.plot(x, f(x), 'b-')
plt.xlabel("x")
plt.ylabel("y")
plt.grid(True)
plt.show()
