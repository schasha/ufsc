#1 N == 0 para o codigo
"""
while True:
    N = int(input("Digite o numero de candidatos."))
    if N == 0:
        break
    while not 1 <= N <= 100 and not N == 0:
        N = int(input("Valor negado, digite novamente."))

    candidatos = {}

    for i in range(N):
        S, P = input(f"Digite o numero do {i + 1}º candidato e o poder dele.").split()
        while not 1 <= len(S) <= 100 or not 1 <= int(P) <= 100 or S in candidatos.keys():
            S, P = input("Nome ou valor negado, digite novamente.(Candidatos com o mesmo nome são negados.)").split()
        candidatos.update({S: int(P)})

    maior_poder = max(candidatos.values())
    
    if list(candidatos.values()).count(maior_poder) == 1:
        print(list(candidatos.keys())[list(candidatos.values()).index(maior_poder)])
    else:
        for i in sorted(list(candidatos.keys())):
            if candidatos[i] == maior_poder:
                print(i)
                break
"""
#2
"""
aposta = [int(i) for i in input("Digite sua aposta.").split()]

acertos = 0

for i in input("Digite o resultado").split():
    if int(i) in aposta:
        acertos += 1 

if acertos == 6:
    print("sena")
elif acertos == 5:
    print("quina")
elif acertos == 4:
    print("quadra")
elif acertos == 3:
    print("terno")
else: print("azar")
"""
#3
"""
def getIndiceAdjacente(i, j, m, n):
    indiceAjdacente = []
    if i > 0:
        indiceAjdacente.append((i-1,j))
    if i+1 < m:
        indiceAjdacente.append((i+1,j))
    if j > 0:
        indiceAjdacente.append((i,j-1))
    if j+1 < n:
        indiceAjdacente.append((i,j+1))
    return indiceAjdacente

N, M = [int(i) for i in input().split()]
pdq = [[int(i) for i in input().split()] for i in range(M)]
tabuleiro = [[i for i in range(N)] for i in range(M)]

for i in range(N):
    for j in range(M):
        c = 0
        if pdq[i][j] == 1:
            c = 9
        else:
            for indice in getIndiceAdjacente(i, j, M, N):
                if pdq[indice[0]][indice[1]] == 1:
                    c += 1
        tabuleiro[i][j] = c

for i in range(N):
    print(tabuleiro[i])
"""