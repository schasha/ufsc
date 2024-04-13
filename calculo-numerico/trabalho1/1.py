def horner(n, coef, x0):
    y, z = coef[0], coef[0]
    for j in range(1, n): # i0 = a_n, i1 = a_n-1, ...
        y = x0 * y + coef[j]
        z = x0 * z + y
    y = x0 * y + coef[-1]
    return y, z

def zeroEstimates(n, coef, interval, segment_num):
    h = abs(interval[1] - interval[0])/segment_num
    point = interval[0]
    roots = []
    limit = 0.1/h
    for i in range(segment_num+1):
        x1 = horner(n, coef, point)[0]
        x2 = horner(n, coef, point+h)[0]
        point += h
        if x1 * x2 <= 0 and abs(x1 - x2) < limit:
            roots.append((2*point + h) * 0.5)
    return roots

def newton(n, coef):
    roots = zeroEstimates(n, coef, [-1, 3], 1000)
    data = [[] for i in range(len(roots))]
    for i in range(len(roots)):
        root = roots[i]
        delta_x = 10**(-5)
        iterations = 0
        data[i].append(root)
        while abs(delta_x) > 10**(-10) and iterations < 100:
            iterations += 1
            y, dy = horner(n, coef, root)
            delta_x = y/dy
            xi = root - delta_x
            root = xi
            data[i].append(root)
        roots[i] = root
    return roots, data

roots, data = newton(4, [1, -3, 1, 1, 1])
i = 0
for root in data:
    print(f"root {i+1}")
    i += 1
    for iteration in root:
        print(iteration)
print(roots)

