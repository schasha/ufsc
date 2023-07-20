from scipy.integrate import quad
from math import log, exp
#1
#Regra 1/3 de simpson
def simpson(function, b, a):
    return ((b - a)/6) * (function(a) + 4 * function((a + b)/2) + function(b))
#a)
f = lambda x: 3*x**2 + 5*x + 2
print(f"{simpson(f, 1, 5):.3f} ,{quad(f, 1, 5)[0]:.3f}")
#b)
g = lambda x: log(x)
print(f"{simpson(g, 1, 7):.3f} ,{quad(g, 1, 7)[0]:.3f}")
#c)
h = lambda x: exp(-0.001*x)
print(f"{simpson(h, 4, 10):.3f} ,{quad(h, 4, 10)[0]:.3f}")
#d)
i = lambda x: exp(x)
print(f"{simpson(i, 0, 2):.3f} ,{quad(i, 0, 2)[0]:.3f}")
#2
def simpson_composite(f, a, b, n):
    assert n % 2 == 0
    assert a <= b
    delta = 2 * (b - a)/n
    integral = 0
    x_2j = a
    for i in range(0, int(n/2)):
        integral += simpson(f, x_2j, x_2j + delta)
        x_2j += delta
    return integral
print(f"{simpson(f, 1, 5):.3f} ,{simpson_composite(f, 1, 5, 2):.3f} ,{quad(f, 1, 5)[0]:.3f}")
print(f"{simpson(g, 1, 7):.3f} ,{simpson_composite(g, 1, 7, 100):.3f} ,{quad(g, 1, 7)[0]:.3f}")
print(f"{simpson(h, 4, 10):.3f} ,{simpson_composite(h, 4, 10, 100):.3f} ,{quad(h, 4, 10)[0]:.3f}")
print(f"{simpson(i, 0, 2):.3f} ,{simpson_composite(i, 0, 2, 100):.3f} ,{quad(i, 0, 2)[0]:.3f}")
