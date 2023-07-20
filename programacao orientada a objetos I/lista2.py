#1          
'''
valor_casa = int(input())
salario = int(input())
qnts_anos = int(input())
prestacoes = qnts_anos*12
if valor_casa/prestacoes > 0.3 * salario:
    print("Emprestimo negado")
else: print(f"Valor da prestacao = {valor_casa/prestacoes}") 
'''
#2
"""
valor = int(input())
metodo_pagamento = input()
if metodo_pagamento == "à vista":
    print(valor*0.1)
elif metodo_pagamento == "1x no cartao":
    print(valor*0.05)
elif metodo_pagamento == "2x cartao":
    print(valor)
elif metodo_pagamento == "3x ou mais no cartao":
    print(valor*1.20)
else: print("Método invalido")
"""
#3
"""
peso = int(input())
altura = float(input())
imc = peso/altura**2
if imc > 40:
    print("obesidade morbida")
elif 30 < imc <= 40:
    print("obesidade")
elif 25 < imc <= 30:
    print("sobrepeso")
elif 18.5 < imc <= 25:
    print("peso ideal")
else: print("abaixo do peso")
"""
#4
"""
nota1, nota2, nota3 = float(input()), float(input()), float(input())
media = (nota1 + nota2 + nota3)/3
if media >= 7:
    print("Aprovado")
elif 5 <= media < 7:
    print("Em recuperacao")
else: print("Reprovado")
"""
#1051
"""
income = float(input())
if income > 4500:
    print(f"R$ {350 + (income - 4500) * 0.28:.2f}")
elif 3000.01 <= income <= 4500:
    print(f"R$ {80 + (income - 3000) * 0.18:.2f}")
elif 2000.01 <= income <= 3000:
    print(f"R$ {(income - 2000) * 0.08:.2f}")
else:
    print("Isento")
"""
#1061
"""
dia_inicio = input().split(" ")
hora_inicio = input().split(" : ")
dia_final = input().split(" ")
hora_final = input().split(" : ")
dias = int(dia_final[1]) - int(dia_inicio[1])
horas = int(hora_final[0]) - int(hora_inicio[0])
minutos = int(hora_final[1]) - int(hora_inicio[1])
segundos = int(hora_final[2]) - int(hora_inicio[2])
if segundos < 0:
    minutos -= 1
    segundos += 60
if minutos < 0:
    horas -= 1
    minutos += 60
if horas < 0:
    dias -= 1
    horas += 24
print(f"{dias} dia(s)\n{horas} hora(s)\n{minutos} minuto(s)\n{segundos} segundo(s)")
"""
#1050
"""
ddd1 = int(input())
ddd = {61: "Brasilia", 71:"Salvador", 11: "Sao Paulo", 21: "Rio de Janeiro", 32:"Juiz de Fora", 19:"Campinas", 27:"Vitoria", 31:"Belo horizonte"}
if ddd1 not in ddd.keys():
    print("DDD nao cadastrado")
"""
#1052
"""
meses = {1:"January", 2:"February", 3:"March", 4:"April", 5:"May", 6:"June", 7:"July", 8:"August", 9:"September", 10:"October", 11:"November", 12:"December"}
print(meses[int(input())])
"""
#1036
"""
abc = input().split(" ")
A, B, C = float(abc[0]), float(abc[1]), float(abc[2])
if B**2 - 4*A*C < 0 or A == 0:
    print("Impossivel calcular")
else: print(f"R1 = {(-B + (B**2 - 4*A*C)**(1/2))/(2 * A):.5f}\nR2 = {(-B - (B**2 - 4*A*C)**(1/2))/(2 * A):.5f}")
"""
#1018
"""
valor = int(input())
notas = {100:0, 50:0, 20:0, 10:0, 5:0, 2:0, 1:0}
print(valor)
for i in notas:
    if valor//i != 0:
        notas[i] += valor//i
        valor -= i*(valor//i)
for i in notas:
    print(f"{notas[i]} nota(s) de R$ {i},00")
"""
#2408
"""
abc = input().split(" ")
A, B, C = int(abc[0]), int(abc[1]), int(abc[2])
if (B > A > C) or (C > A > B):
    print(A)
elif (A > B > C) or (C > B > A):
    print(B)
else: print(C)
"""
#2417
"""
dados = input().split(" ")
pontos_C = int(dados[0]) * 3 + int(dados[1])
pontos_F = int(dados[3]) * 3 + int(dados[4])
if pontos_C > pontos_F:
    print("C")
elif pontos_C == pontos_F and int(dados[2]) > int(dados[5]):
    print("C")
elif pontos_C == pontos_F and int(dados[2]) == int(dados[5]):
    print("=")
else: print("F")
"""
#2568
"""
dados = input().split(" ")
D, I, X, F = int(dados[0]), int(dados[1]), int(dados[2]), int(dados[3])
if len(range(D, D + F + 1)) % 2 != 0:
    print(I)
elif (D + F) % 2 == 0:
    print(I + X)
else: print(I - X)
"""
#2600
"""
times = int(input())
while times > 0:
    #variaveis temporarias
    times -= 1
    result1 = False
    result2 = False
    dado_comum = list("123456")
    #input do beecrowd
    dado_teste = []
    dado_teste.append(input())
    lado = input().split(" ")
    for i in range(4):
        dado_teste.append(lado[i])
    dado_teste.append(input())
    #checar soma das faces
    if int(dado_teste[0]) + int(dado_teste[5]) != 7:
            result1 = False
    elif int(dado_teste[1]) + int(dado_teste[3]) != 7:
            result1 = False
    elif int(dado_teste[2]) + int(dado_teste[4]) != 7:
            result1 = False
    else: result1 = True
    #checar numero das faces
    for i in range(6):
        if dado_teste[i] in dado_comum:
            result2 = True
            dado_comum.remove(dado_teste[i])
        else:
            result2 = False
            break
    #resultado final
    if result1 and result2: 
        print("SIM")
    else: print("NAO")
"""
#1046
"""
input = input().split(" ")
horas_totais = int(input[1]) - int(input[0])
if horas_totais < 1:
    print(f"O JOGO DUROU {horas_totais + 24} HORA(S)")
else: print(f"O JOGO DUROU {horas_totais} HORA(S)")
"""
#1047
"""
input = input().split(" ")
horas = int(input[2]) - int(input[0])
minutos = int(input[3]) - int(input[1])
if minutos < 0:
    horas -= 1
    minutos += 60
if horas < 0:
    horas += 24
if horas == 0 and minutos == 0:
    horas += 24
print(f"O JOGO DUROU {horas} HORA(S) E {minutos} MINUTO(S)")
"""
#1048
"""
salario = float(input())
if salario > 2000:
    print(f"Novo salario: {salario * 1.04:.2f}\nReajuste ganho: {salario * 0.04:.2f}\nEm percentual: 4 %")
elif 1200.01 <= salario <= 2000:
    print(f"Novo salario: {salario * 1.07:.2f}\nReajuste ganho: {salario * 0.07:.2f}\nEm percentual: 7 %") 
elif 800.01 <= salario <= 1200:
    print(f"Novo salario: {salario * 1.1:.2f}\nReajuste ganho: {salario * 0.1:.2f}\nEm percentual: 10 %")
elif 400.01 <= salario <= 800:
    print(f"Novo salario: {salario * 1.12:.2f}\nReajuste ganho: {salario * 0.12:.2f}\nEm percentual: 12 %")
else: print(f"Novo salario: {salario * 1.15:.2f}\nReajuste ganho: {salario * 0.15:.2f}\nEm percentual: 15 %")
"""
#2375
"""
diametro = int(input())
caixa = input().split(" ")
if diametro <= int(caixa[0]) and diametro <= int(caixa[1]) and diametro <= int(caixa[2]):
    print("S")
else: print("N")
"""
#2409
"""
colchao = input().split(" ")
porta = input().split(" ")
colchaoA, colchaoB, colchaoC = int(colchao[0]), int(colchao[1]), int(colchao[2])
portaH, portaL = int(porta[0]), int(porta[1])
H = False
L = False
#porta H 
if portaH > colchaoA or portaH > colchaoB or portaH > colchaoC:
    H = True
#porta L dependendo de H
if portaH > colchaoA:
    if portaL > colchaoB or portaL > colchaoC:
        L = True
if portaH > colchaoB:
    if portaL > colchaoA or portaL > colchaoC:
        L = True
if portaH > colchaoC:
    if portaL > colchaoB or portaL > colchaoA:
        L = True
#resultado final
if H and L:
    print("S")
else: print("N")
"""