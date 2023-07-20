#1
"""
N = int(input())
while N >    0:

    suspeitos = [int(i) for i in input().split()]
    maior = 1
    maior2nd = 1
    for i in range(N):
        if suspeitos[i] > maior:
            maior = suspeitos[i]

    for i in range(N):
        if maior2nd < suspeitos[i] < maior:
            maior2nd = suspeitos[i]

    print(suspeitos.index(maior2nd) + 1)

    N = int(input())
"""
#2
"""
N = int(input())
lista = [int(i) for i in input().split()]

mult = [0, 0, 0, 0]

for i in range(N):
    if lista[i] % 2 == 0:
        mult[0] += 1
    if lista[i] % 3 == 0:
        mult[1] += 1
    if lista[i] % 4 == 0:
        mult[2] += 1
    if lista[i] % 5 == 0:
        mult[3] += 1
    
print(f"{mult[0]} Multiplo(s) de 2\n{mult[1]} Multiplo(s) de 3\n{mult[2]} Multiplo(s) de 4\n{mult[3]} Multiplo(s) de 5")
"""
#3
def somaPar():
    soma = 0
    for i in range(N):
        for j in range(N):
            if M[i][j] % 2 == 0:
                soma += M[i][j]
    return soma

def mediaDiagonal():
    soma = 0
    for i in range(N):
        soma += M[i][i]
    media = soma/N
    return media

def produtoDiagonal2nd():
    produto = 1
    for i in range(N):
        produto *= M[i][-(i + 1)]
    return produto

def mediaAcima():
    soma = 0
    count = 0
    L = N - 1
    for i in range(N):
        for j in range(L):
            soma += M[i][-(j + 1)]
            count += 1
        L -= 1
    media = soma/count
    return media

def somaColunaN():
    soma = 0
    for i in range(N):
        soma += M[i][N - 1]
    return soma

def menorLinha1():
    menor = 1000000000
    for i in range(N):
        if M[0][i] < menor:
            menor = M[0][i]
    return menor


N = int(input("Digite a ordem da matriz."))

M = [[j for j in range(N)] for i in range(N)]
for i in range(N):
    for j in range(N):
        M[i][j] = int(input(f"Digite o elemento {i, j} da matriz."))

for i in range(N):
    print(M[i])


while True:
    P = input("Digite o que deseja:\na) Mostre a soma de todos os elementos pares da matriz.\nb) Mostre a média dos elementos da diagonal principal.\nc) Mostre o produto dos elementos da diagonal secundária.\nd) Mostre a média dos elementos acima da diagonal principal.\ne) Mostre a soma dos elementos da última coluna da matriz.\nf) Mostre o menor valor da primeira linha da matriz.\ng) Sair.\n").lower()

    if P == "a":
        print(somaPar())
    elif P == "b":
        print(mediaDiagonal())
    elif P == "c":
        print(produtoDiagonal2nd()) 
    elif P == "d":
        print(mediaAcima())
    elif P == "e":
        print(somaColunaN())
    elif P == "f":
        print(menorLinha1())
    elif P == "g":
        break
