#1113
"""
while True:
    num = input().split(" ")
    num1, num2 = int(num[0]), int(num[1])
    if num1 != num2:
        if num1 > num2:
            print("Decrescente")
        else: print("Crescente")
    else: break 
"""
#1099
"""
N = int(input())
for i in range(N):
    num = input().split(" ")
    num1, num2 = int(num[0]), int(num[1])
    sum = 0
    if num1 < num2:
        for i in range(num1 + 1, num2):
            if i % 2 != 0:
                sum += i
    else: 
        for i in range(num1 - 1, num2, -1):
            if i % 2 != 0:
                sum += i
    print(sum)
"""
#1021
"""
valor = float(input())
notas = {100:0, 50:0, 20:0, 10:0, 5:0, 2:0}
moedas = {1.00:0, 0.50:0, 0.25:0, 0.10:0, 0.05:0, 0.01:0}
for i in notas:
    if valor//i != 0:
        notas[i] += valor//i
        valor -= i*(valor//i)
for i in moedas:
    if i == 0.01:
        if round(valor/i, 2) != 0:
            moedas[i] += round(valor/i, 2)
            valor -= i*round(valor/i, 2)
    else:
        if valor//i != 0:
            moedas[i] += valor//i
            valor -= i*(valor//i)
print("NOTAS:")
for i in notas:
    print(f"{int(notas[i])} nota(s) de R$ {i}.00")
print("MOEDAS:")
for i in moedas:
    print(f"{int(moedas[i])} moeda(s) de R$ {i:.2f}")
"""
#1247
"""
from sys import stdin
for line in stdin:
    D, Vf, Vg = [int(i) for i in line.split()]
    if (((12**2)+(D**2))**(1/2))/Vg <= 12/Vf:
        print("S")
    else: print("N")
"""
#1708
"""
time = [int(i) for i in input().split(" ")]
lap = 1
time_difference = 0
while True:
    if time_difference >= time[0]:
        break   
    time_difference += time[1] - time[0]
    lap += 1    
print(lap)
"""
#2418
"""
notas = [float(i) for i in input().split(" ")]
menor = 0
maior = 11
for i in range(5):
    if notas[i] >= notas[0] and notas[i] >= notas[1] and notas[i] >= notas[2] and notas[i] >= notas[3] and notas[i] >= notas[4]:
        maior = notas[i]
    if notas[i] <= notas[0] and notas[i] <= notas[1] and notas[i] <= notas[2] and notas[i] <= notas[3] and notas[i] <= notas[4]:
        menor = notas[i]
soma = 0 - menor - maior
for i in range(5):
    soma += notas[i]
print(round(soma, 1))
"""
#2247
"""
N = 1
u = 1
while True:
    N = int(input())
    if N == 0:
        break
    diferenca = 0
    print(f"Teste {u}")
    u += 1
    for i in range(N):
        cofres = [int(m) for m in input().split(" ")]
        diferenca += cofres[0] - cofres[1]
        print(diferenca)
"""
#2187
"""
V = 1
count = 1
while 0 <= V <= 10000:
    V = int(input())
    if V == 0:
        break
    print(f"Teste {count}")
    count += 1
    I, J, K, L = 0, 0, 0, 0
    if V//50 != 0:
        I += V//50
        V -= 50*(V//50)
    if V//10 != 0:
        J += V//10
        V -= 10*(V//10)
    if V//5 != 0:
        K += V//5
        V -= 5*(V//5) 
    if V//1 != 0:
        L += V//1
        V -= 1*(V//1)
    print(I, J, K, L)
    print("")
    V = 1
"""
#2376
"""
teams = [i for i in "ABCDEFGHIJKLMNOP"]
for i in range(8):
    score = [int(i) for i in input().split(" ")]
    if score[0] < score[1]:
        teams.pop(0 + i)
    else: teams.pop(1 + i)
for i in range(4):
    score = [int(i) for i in input().split(" ")]
    if score[0] < score[1]:
        teams.pop(0 + i)
    else: teams.pop(1 + i)
for i in range(2):
    score = [int(i) for i in input().split(" ")]
    if score[0] < score[1]:
        teams.pop(0 + i)
    else: teams.pop(1 + i)
score = [int(i) for i in input().split(" ")]
if score[0] < score[1]:
        teams.pop(0)
else: teams.pop(1)
print(teams[0])
"""
#2229
"""
N = 1
count = 1
while -1 <= N <= 15:
    N = int(input())
    if N == -1:
        break
    print(f"Teste {count}")
    count += 1
    M = 0
    for i in range(N):
        M += 2**i
    print((2 + M)**2)
    print("")
"""
#1150
"""
X = int(input())
Z = 0
while X >= Z:
    Z = int(input())
sum1 = 0
count = 0
while Z > sum1:
    sum1 += X
    X += 1
    count += 1
print(count)
"""
#2424
"""
x0, y0 = 0, 0
xa, ya = 432, 468
entry = [int(i) for i in input().split(" ")]
x, y = entry[0], entry[1]
if x0 <= x <= xa and y0 <= y <= ya:
    print("dentro")
else: print("fora")
"""
#2454
"""
entry = [int(i) for i in input().split(" ")]
if entry[0] == 1:
    if entry[1] == 1:
        print("A")
    else: print("B")
else: print("C")
"""
#2373
"""
cups = 0
for i in range(int(input())):
    entry = [int(i) for i in input().split(" ")]
    L, C = entry[0], entry[1]
    if L > C:
        cups += C
print(cups)
"""
#1323
"""
while True:
    N = int(input())
    if N == 0:
        break
    squares = 0
    M = 0
    for i in range(N + 1):
        M += i**2
    print(M)
"""
#2295
"""
entry = [float(i) for i in input().split(" ")]
pkmA = entry[0]/entry[2]
pkmG = entry[1]/entry[3]
if pkmA < pkmG: 
    print("A")
else: print("G")
"""