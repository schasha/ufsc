#1
"""
while True:
    try:
        entry = input()
        S = [int(i) for i in input().split(" ")]

        N, R = [int(i) for i in entry.split(" ")]
        M = [i + 1 for i in range(N)]
        
        for i in range(len(S)):
            M.remove(S[i])
            
        if len(M) == 0:
            print("*")
        else:
            for i in range(len(M)):
                print(M[i], end = " ")
            print()
    except EOFError:
        break
"""
#2
"""
P, N = [int(i) for i in input().split()]
C = [int(i) for i in input().split()]
flag = True
for i in range(N - 1): 
        if P >= abs(C[i] - C[i+1]):
            pass
        else:
            flag = False
            break
if flag == True:
    print("YOU WIN")
else: print("GAME OVER")
"""
#3
"""
#N participantes
#M problemas

#Ninguém resolveu todos os problemas.
def todosProblemasPessoa(N, M):
    global cond
    for i in range(N):
        count = 0
        flag = True
        for j in range(M):
            count += T[i][j]
        if count == M:
            flag = False
            break
    if flag: cond += 1

#Todo problema foi resolvido por pelo menos uma pessoa (não necessariamente a mesma).
def todosProblemas(N, M):
    global cond
    count = 0
    for j in range(M):
        for i in range(N):
            if T[i][j] == 1:
                count += 1
                break
    if count == M:
        cond += 1

#Não há nenhum problema resolvido por todos.
def problemaTodos(N, M):
    global cond
    for j in range(M):
        count = 0
        flag = True
        for i in range(N):
            count += T[i][j]
        if count == N:
            flag = False
            break
    if flag: cond += 1

#Todos resolveram ao menos um problema (não necessariamente o mesmo)
def todosUmProblema(N, M):
    global cond
    count = 0 
    for i in range(N):
        for j in range(M):
            if T[i][j] == 1:
                count += 1
                break
    if count == N:
        cond += 1

N, M = [int(i) for i in input().split()]
while M != 0 and N != 0:

    T = []
    for i in range(N):
        linha = [int(i) for i in input().split()]
        T.append(linha)

    cond = 0
    todosProblemasPessoa(N, M)
    todosProblemas(N, M)
    problemaTodos(N, M)
    todosUmProblema(N, M)
    
    print(cond)

    N, M = [int(i) for i in input().split()]
"""