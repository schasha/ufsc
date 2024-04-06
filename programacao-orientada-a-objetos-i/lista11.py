#1
"""
import random
L = int(input("Digite o numero da coluna alvo."))
T = input("Digite qual o calculo desejado (S/M)").upper()
I = int(input("Digite o numero de linhas da matriz."))
J = int(input("Digite o numero de colunas da matriz"))

M = [[i for i in range(J)] for i in range(I)]
for i in range(I):
    for j in range(J):
        M[i][j] = random.randrange(100)
for i in range(I):
    print(M[i])

count = 0
for i in range(12):
    count += M[L][i]
if T == "S":
    print(f"{count:.1f}")
else: print(f"{count/12:.1f}")
"""
#2
"""
import random

I = int(input("Digite o numero de linhas da matriz."))
J = int(input("Digite o numero de colunas da matriz"))
R = input("Deseja uma matriz aleatoria ? (S/N)").upper()
T = input("Digite qual o calculo desejado (S/M)").upper()

M = [[i for i in range(J)] for i in range(I)]

if R == "S":
    for i in range(I):
        for j in range(J):
            M[i][j] = random.randrange(100)
else:
     for i in range(I):
        for j in range(J):
            M[i][j] = int(input(f"Digite o elemento {i},{j} da matriz"))

for i in range(I):
    print(M[i])

count = 0
L = 1
for i in range(11):
    for j in range(L):
        count += M[L][j]
        M[L][j] = 1
    L += 1

if T == "S":
    print(f"{count:.1f}")
else: print(f"{count/66:.1f}")
"""
#3
"""
Q = int(input())
entry = input()

list = [int(i) for i in entry.split(" ")]

count = 0
for i in range(Q):
    count += list[i]

if count >= Q/2:
    print("N")
else: print("Y")
"""