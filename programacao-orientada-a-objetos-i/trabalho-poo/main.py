from paciente import Paciente
from medico import *
from enfermeiro import *

paciente_lista = []
idP = 1
p = Paciente("Davi", "48998671568", "12345432344", str(idP), "176", "85", "Gripe", {"Médicos": [], "Enfermeiros": []})
paciente_lista.append(p)
medicos_lista = [m1, m2, m3]
enfermeiros_lista = [e1, e2, e3]

while True:
    print("Selecione o que você deseja fazer.")
    print("1. Listar pacientes.")
    print("2. Ver a ficha de um paciente.")
    print("3. Registrar um paciente.")
    print("4. Alterar os dados de um paciente.")
    print("5. Outros(médicos e enfermeiros). ")
    print("6. Sair.")

    s = int(input())
    while not 1 <= s <= 6:
        s = int(input("Opção invalida, digite novamente. "))
    
    if s == 1:
        for i in range(len(paciente_lista)):
            print(f"Número de identificação: {paciente_lista[i].getId()} Nome: {paciente_lista[i].getNome()}")


    elif s == 2:
        id = int(input("Digite o número de identificação do paciente. "))
        if 1 <= id <= idP:
            for i in range(len(paciente_lista)):
                if id == int(paciente_lista[i].getId()):
                    print(paciente_lista[i])
        else: print("Número de identificação invalido.")


    elif s == 3:
        idP += 1
        p = Paciente(input("Digite o nome. "), input("Digite o número de telefone. "), input("Digite o CPF. "), str(idP), input("Digite a altura(somente números). "), input("Digite o peso(somente números). "), input("Digite o diagnóstico. "), {"Médicos": [], "Enfermeiros": []})
        paciente_lista.append(p)


    elif s == 4:
        k = paciente_lista[int(input("Digite o número de identificação do paciente que você deseja alterar os dados. ")) - 1]
        i = input("Digite qual dado você quer alterar ou se quer deletar o paciente(Nome, Telefone, CPF, Altura, Peso, Diagnóstico, Deletar). ").lower()
        if i == "nome":
            k.setNome(input("Digite o novo nome. "))
        elif i == "telefone":
            k.setTelefone(input("Digite o novo telefone. "))
        elif i == "cpf":
            k.setCpf(input("Digite o novo CPF. "))
        elif i == "altura":
            k.setAltura(input("Digite a nova altura. "))
        elif i == "peso":
            k.setPeso(input("Digite o novo peso. "))
        elif i == "diagnostico":
            k.setDiagnostico(input("Digite o novo diagnóstico. "))
        elif i == "deletar":
            del k
        else: print("Comando invalido.")


    elif s == 5:
        print("Selecione o que você deseja fazer.")
        print("1. Listar médicos.")
        print("2. Ver dados de um médico.")
        print("3. Listar enfermeiros.")
        print("4. Ver os dados de um enfermeiro.")
        print("5. Associar à equipe")

        u = int(input())

        if u == 1:
            for i in range(len(medicos_lista)):
                print(medicos_lista[i].getNome())

        elif u == 2:
            i = input("Digite o nome do médico. ").title()
            for j in range(len(medicos_lista)):
                if i == medicos_lista[j].getNome():
                    print(medicos_lista[j])

        elif u == 3:
            for i in range(len(enfermeiros_lista)):
                print(enfermeiros_lista[i].getNome())

        elif u == 4:
            i = input("Digite o nome do enfermeiro. ").title()
            for j in range(len(enfermeiros_lista)):
                if i == enfermeiros_lista[j].getNome():
                    print(enfermeiros_lista[j])

        elif u == 5:
            k = paciente_lista[int(input("Digite o número de identificação do paciente que você deseja associar uma equipe. ")) - 1]
            k.associar(medicos_lista, enfermeiros_lista)
            for i in medicos_lista:
                if i.getNome() in k.getEquipe()["Médicos"] and k.getNome() not in i.getPacientes():
                    i.pacientes.append(k.getNome())
            for i in enfermeiros_lista:
                if i.getNome() in k.getEquipe()["Enfermeiros"] and k.getNome() not in i.getPacientes():
                    i.pacientes.append(k.getNome())

        else: print("Opção invalida.")

    elif s == 6:
        break
