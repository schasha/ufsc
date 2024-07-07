import numpy as np
import matplotlib.pyplot as plt

beta = 10 / (40 * 8 * 24)
gamma = 3 / (15 * 24)

def sir(t, y):
    S, I, R = y
    dSdt = -beta * S * I
    dIdt = beta * S * I - gamma * I
    dRdt = gamma * I
    return np.array([dSdt, dIdt, dRdt])

def rk4_step(f, t, y, h):
    k1 = h * f(t, y)
    k2 = h * f(t + 0.5 * h, y + 0.5 * k1)
    k3 = h * f(t + 0.5 * h, y + 0.5 * k2)
    k4 = h * f(t + h, y + k3)
    y_next = y + (k1 + 2*k2 + 2*k3 + k4) / 6
    return y_next

def solve(f, y0, t0, t_end, h):
    t_values = np.arange(t0, t_end, h)
    y_values = np.zeros((len(t_values), len(y0)))
    
    y = y0
    for i, t in enumerate(t_values):
        y_values[i] = y
        y = rk4_step(f, t, y, h)
    
    return t_values, y_values

# initial values
y0 = np.array([49, 1, 0])
t0 = 0

t_end = 25
h = 0.01

# a)
t_values, y_values = solve(sir, y0, t0, t_end, h)

# plot
plt.plot(t_values, y_values[:, 0], label='S(t)')
plt.plot(t_values, y_values[:, 1], label='I(t)')
plt.plot(t_values, y_values[:, 2], label='R(t)')
plt.legend()
plt.xlabel('t')
plt.ylabel('Population')
plt.title('SIR Model')
plt.grid(True)
plt.show()

# b)
beta /= 2

t_values, y_values = solve(sir, y0, t0, t_end, h)

# plot
plt.plot(t_values, y_values[:, 0], label='S(t)')
plt.plot(t_values, y_values[:, 1], label='I(t)')
plt.plot(t_values, y_values[:, 2], label='R(t)')
plt.legend()
plt.xlabel('t')
plt.ylabel('Population')
plt.title('SIR Model | Beta /= 2')
plt.grid(True)
plt.show()
