
#1003
"""
A = int(input())
B = int(input())
soma = A + B
print("SOMA =", soma)
"""
#1004
"""
A = int(input())
B = int(input())
prod = A * B
print("PROD =", prod)
"""
#1005
"""
A = float(input())
B = float(input())
media = (A*3.5 + B*7.5)/11
print(f"MEDIA = {media:.5f}")
"""
#1006
"""
A = float(input())
B = float(input())
C = float(input())
media = (A*2 + B*3 + C*5)/10
print(f"MEDIA = {media:.1f}")
"""
#1007
"""
A = int(input())
B = int(input())
C = int(input())
D = int(input())
diferenca = A*B - C*D
print("DIFERENCA =", diferenca)
"""
#1008
"""
number = int(input())
work_hours = int(input())
hourly_wage = float(input())
print(f"NUMBER = {number}\nSALARY = U$ {hourly_wage*work_hours:.2f}")
"""
#1009
"""
salesperson = input()
salary = float(input())
total_sales = float(input())
print(f"TOTAL = R$ {salary + total_sales*0.15:.2f}")
"""
#1012 para lista
"""
A = float(input())
B = float(input())
C = float(input()) 
print(f"TRIANGULO: {A*C/2:.3f}\nCIRCULO: {C**2 * 3.14159:.3f}\nTRAPEZIO: {(A + B) * C/2:.3f}\nQUADRADO: {B**2:.3f}\nRETANGULO: {A*B:.3f}")
"""
#1012 para o beecrowd
"""
values = input().split(" ")
A = float(values[0])
B = float(values[1])
C = float(values[2])
print(f"TRIANGULO: {A*C/2:.3f}\nCIRCULO: {C**2 * 3.14159:.3f}\nTRAPEZIO: {(A + B) * C/2:.3f}\nQUADRADO: {B**2:.3f}\nRETANGULO: {A*B:.3f}")
"""
#1014
"""
distance = int(input())
fuel = float(input())
print(f"{distance/fuel:.3f} km/l")
"""
#1015
"""
p1 = input().split(" ")
p2 = input().split(" ")
x1, y1 = float(p1[0]), float(p1[1])
x2, y2 = float(p2[0]), float(p2[1])
print(f"{((x2 - x1)**2 + (y2 - y1)**2)**0.5:.4f}")
"""
#1017
"""
time = int(input())
velocity = int(input())
print(f"{(time * velocity)/12:.3f}")
"""
#1019
"""
N = int(input())
print(f"{N//3600}:{N%3600//60}:{(N%3600)%60}")
"""
#1020
"""
N = int(input())
print(f"{N//365} ano(s)\n{(N%365)//30} mes(es)\n{(N%365)%30} dia(s)")
"""
#2374
"""
pressao_lida = int(input())
pressao_desejada = int(input())
print(pressao_lida - pressao_desejada)
"""
#2413
"""
N = int(input())
print(N*4)
"""