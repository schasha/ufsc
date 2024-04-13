import cmath

def horner(n, coef, x0):
    y = coef[0]
    for j in range(1, n): # i0 = a_n, i1 = a_n-1, ...
        y = x0 * y + coef[j]
    y = x0 * y + coef[-1]
    return y

def zeroEstimates(n, coef, interval, segment_num):
    h = abs(interval[1] - interval[0])/segment_num
    point = interval[0]
    roots = []
    limit = 0.1/h
    for i in range(segment_num+1):
        x1 = horner(n, coef, point)
        x2 = horner(n, coef, point+h)
        point += h
        if x1 * x2 <= 0 and abs(x1 - x2) < limit:
            val = (2*point + h) * 0.5
            roots.append([val-h, val, val+h])
    return roots

def muller(n, coef):
    aproximations = zeroEstimates(n, coef, [1, 3], 1000)
    aproximations.append([-0.5, 0, 0.5])
    roots = []
    data = [[] for i in range(len(aproximations))]
    for i in range(len(aproximations)):
        apr = aproximations[i] 
        x = apr[2]
        iterations = 2
        data[i].append(apr)
        while abs(horner(n, coef, x)) > 10**(-10) and iterations < 100:
            iterations += 1
            x0, x1, x2 = apr
            fx0 = horner(n, coef, x0)
            fx1 = horner(n, coef, x1)
            fx2 = horner(n, coef, x2)

            c = fx2
            q0 = (fx0 - fx2)/(x0 - x2)
            q1 = (fx1 - fx2)/(x1 - x2)
            a = (q0 - q1)/(x0 - x1)
            b = q0 * (x2 - x1)/(x0 - x1) + q1 * (x0 - x2)/(x0 - x1)

            x = x2 - 2*c/(b + (b/abs(b)) * cmath.sqrt(b*b - 4*a*c))
            apr = [x1, x2, x]
            data[i].append(apr)
        if (apr[2].imag != 0):
            roots.append(complex(apr[2].real, -apr[2].imag))
        roots.append(apr[2])
    return roots, data

roots, data = muller(4, [1, -3, 1, 1, 1])
i = 0
for root in data:
    print(f"root {i+1}")
    i += 1
    for iteration in root:
        print(iteration)
print(roots)
