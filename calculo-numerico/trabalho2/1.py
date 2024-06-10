import numpy as np
import matplotlib.pyplot as plt

def newton_system(f, J, x0, tol=1e-6, max_it=20):
    i = 0
    x = x0
    while i < max_it:
        i += 1

        fx = f(x)
        Jx = J(x)
        
        if np.linalg.det(Jx) != 0:
            delta_x = np.linalg.solve(Jx, -fx)
            x += delta_x
        
            # convergence 
            if np.linalg.norm(delta_x) < tol:
                return x, i + 1
    
    return x, max_it

# a
def fa(x):
    return np.array([
        x[0]**2 - x[1]**2 - 1,
        2*x[0] * x[1]
    ])

def Ja(x):
    return np.array([
        [2*x[0], -2*x[1]],
        [2*x[1], 2*x[0]]
    ])

sol = np.array([[1, 0],  [-1,0]])
n = 100
map = []
map_it = []
for i in range(n):
    map.append([])
    map_it.append([])
    for j in range(n):
        t = np.array([-1 + 2*i/n, -1 + 2*j/n])
        x, it = newton_system(fa, Ja, t)
        if (x == sol[0]).all():
            map[i].append(1)
        elif (x == sol[1]).all():
            map[i].append(2)
        else:
            map[i].append(0)
        map_it[i].append(it)

a = np.array(map)

plt.figure()
plt.imshow(a, alpha=0.8)
plt.xlabel('x')
plt.ylabel('y')
plt.title('solutions map')

a = np.array(map_it)

plt.figure()
plt.imshow(a, alpha=0.8)
plt.xlabel('x')
plt.ylabel('y')
plt.title('iterations map')

# b
def fb(x):
    return np.array([
        x[0]**3 - 3*x[0]*x[1]**2 - 1,
        3*x[1]*x[0]**2 - x[1]**3
    ])

def Jb(x):
    return np.array([
        [3*x[0]**2 - 3*x[1]**2, 6*x[0]*x[1]],
        [6*x[0]*x[1], 3*x[0]**2 - 3*x[1]**2]
    ])

sol = np.array([[1, 0],  [-1/2,-np.sqrt(3)/2], [-1/2, np.sqrt(3)/2]])
n = 100
map = []
map_it = []
for i in range(n):
    map.append([])
    map_it.append([])
    for j in range(n):
        t = np.array([-1.5 + 3*i/n, -1.5 + 3*j/n])
        x, it = newton_system(fa, Ja, t)
        if (x == sol[0]).all():
            map[i].append(1)
        elif (x == sol[1]).all():
            map[i].append(2)
        elif (x == sol[2]).all():
            map[i].append(3)
        else:
            map[i].append(0)
        map_it[i].append(it)

a = np.array(map)

plt.figure()
plt.imshow(a, alpha=0.8)
plt.xlabel('x')
plt.ylabel('y')
plt.title('solutions map')

a = np.array(map_it)

plt.figure()
plt.imshow(a, alpha=0.8)
plt.xlabel('x')
plt.ylabel('y')
plt.title('iterations map')
