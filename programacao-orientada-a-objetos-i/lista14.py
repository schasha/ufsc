#1282 / 1
"""
def feira():
    soma = 0

    M = int(input())
    produtos = {}
    for i in range(M):
        entry = input().split()
        produtos.update({entry[0]: float(entry[1])})

    P = int(input())
    for i in range(P):
        entry = [i for i in input().split()]
        soma += produtos[entry[0]] * int(entry[1])

    return soma

N = int(input())
for i in range(N):
    print(f"R$ {feira():.2f}")
"""
#2482 / 2
"""
N = int(input())
fn = {}

for i in range(N):
    fn.update({input(): input()})

M = int(input())
for i in range(M):
    print(input())
    print(fn[input()])
    print()
"""
#1911 / 3 
"""
while True:
    N = int(input())
    if N == 0:
        break
        
    alunosOriginal = {}
    for i in range(N):
        nome, assinatura = input().split()
        alunosOriginal[nome] = assinatura

    M = int(input())
    falsas = 0
    for i in range(M):
        nome, assinatura = input().split()
        c, countletras = 0, 0 
        for i in assinatura: #assinatura da aula letra a letra
            if i != alunosOriginal[nome][c]:
                countletras += 1
            c += 1
        if countletras > 1: 
            falsas += 1
    print(falsas)
"""
#1763 / 4
"""
fn = {"brasil": "Feliz Natal!",
       "alemanha": "Frohliche Weihnachten!",
       "austria": "Frohe Weihnacht!",
       "coreia": "Chuk Sung Tan!",
       "espanha": "Feliz Navidad!",
       "grecia": "Kala Christougena!",
       "estados-unidos": "Merry Christmas!",
       "inglaterra": "Merry Christmas!",
       "australia": "Merry Christmas!",
       "portugal": "Feliz Natal!",
       "suecia": "God Jul!",
       "turquia": "Mutlu Noeller",
       "argentina": "Feliz Navidad!",
       "chile": "Feliz Navidad!",
       "mexico": "Feliz Navidad!",
       "antardida": "Merry Christmas!",
       "canada": "Merry Christmas!",
       "irlanda": "Nollaig Shona Dhuit!",
       "belgica": "Zalig Kerstfeest!",
       "italia": "Buon Natale!",
       "libia": "Buon Natale!",
       "siria": "Milad Mubarak!",
       "marrocos": "Milad Mubarak!",
       "japao": "Merii Kurisumasu!" }

while True:
  try:
    nome = input()
    if nome in fn.keys():
        print(fn[nome])
    else: print("--- NOT FOUND ---")

  except EOFError:
    break
"""
#1430 / 5
"""
entry = input()
notas = {"W": 1, "H": (1/2), "Q": (1/4), "E": (1/8), "S": (1/16), "T": (1/32), "X": (1/64)}
while True:
    x = entry.strip("/").split("/")
    count = 0
    for compasso in x:
        soma = 0
        for nota in compasso:
            soma += notas[nota]
        if soma == 1:
            count += 1
    print(count)

    entry = input()
    if entry == "*":
        break
"""
#2091 / 6 
"""
def teste():
    lista = [int(i) for i in input().split()]
    numeros = {}
    
    for i in lista:
        if i not in numeros.keys():
            numeros.update({i: lista.count(i)})
    
    for i in numeros.keys():
        if numeros[i] % 2 != 0:
            print(i)
            break

    
N = int(input())
while N != 0:
    teste()
    N = int(input())
"""
#1953 / 7 
"""
while True:
    try:
        alunos = {"EPR": 0, "EHD": 0, "INTRUSOS": 0}

        for i in range(int(input())):
            entry = [i for i in input().split()]
            if entry[1] in alunos.keys():
                alunos[entry[1]] += 1
            else: alunos["INTRUSOS"] += 1

        print(f"EPR: {alunos['EPR']}\nEHD: {alunos['EHD']}\nINTRUSOS: {alunos['INTRUSOS']}")

    except EOFError:
        break
"""
#1261 / 8
"""
palavras = {}

M, N = [int(i) for i in input().split()]

for i in range(M):
    entry = [i for i in input().split()]
    palavras.update({entry[0]: int(entry[1])})

for i in range(N):
    salario = 0
    I = input()
    while I != ".":
        for word in I.split():
            if word in palavras.keys():
                salario += palavras[word]
        I = input()
    print(salario)
"""
#2478 / 9
"""
def comp(I):
    guess = [i for i in I.strip().split()]
    if guess[0] in participantes.keys():
        if guess[1] in participantes[guess[0]]:
            print("Uhul! Seu amigo secreto vai adorar o/")
        else: print("Tente Novamente!")
    else: print("Tente Novamente!")

P = int(input())

participantes = {}
for i in range(P):
    entry = [i for i in input().strip().split()]
    participantes.update({entry[0]: [entry[1], entry[2], entry[3]]})


while True:
    try:
        comp(input())
        
    except EOFError:
        break
"""
#10
"""
def cadastro(nome, anoNasc, cartTrab):
    if cartTrab == 0:  
        usuarios.append({"Nome": nome, "Idade": (2022 - int(anoNasc)), "Carteira de trabalho": cartTrab})
    else:
        contratAno = int(input("Digite o ano de contratação."))
        usuarios.append({"Nome": nome, "Idade": (2022 - int(anoNasc)), "Carteira de trabalho": cartTrab, "Ano de contratação": contratAno, "Salário": input("Digite o salário."), "Aposentadoria.": (contratAno + 35) })
    print(usuarios)
      
usuarios = []

while True:
    N = int(input("Digite o que deseja fazer:\n1. Cadastrar usúario.\n2. Imprimir dados(1 usuario).\n3. Imprimir dados(todos usuarios).\n4. Encerrar o programa."))
    if N == 1:
        cadastro(input("Digite seu nome."), int(input("Digite sua data de nascimento.")), int(input("Digite o número da sua carteria de trabalho, se não tiver, digte 0.")))
    elif N == 2:
        u = input("Digite o nome do usuario.")
        for i in range(len(usuarios)):
            if u == usuarios[i]["Nome"]:
                print(usuarios[i])
                break
    elif N == 3:
        print(usuarios)
    else:
        break
"""