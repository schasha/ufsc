from pessoa import Pessoa

class Paciente(Pessoa):
    def __init__(self, nome, telefone, cpf, idP, altura, peso, diagnostico, equipe):
        super().__init__(nome, telefone, cpf)
        self.id = idP
        self.altura = altura
        self.peso = peso
        self.diagnostico = diagnostico
        self.equipe = equipe

    def getId(self):
        return self.id
    def getAltura(self):
        return self.altura
    def getPeso(self):
        return self.peso
    def getDiagnostico(self):
        return self.diagnostico
    def getEquipe(self):
        return self.equipe

    def setId(self, i):
        self.input = i
    def setAltura(self, i):
        self.altura = i
    def setPeso(self, i):
        self.peso = i
    def setDiagnostico(self, i):
        self.diagnostico = i


    def __str__(self):
        string = ""
        string += f"Nome:                    {self.nome}\n"
        string += f"Telefone:                {self.telefone}\n"
        string += f"CPF:                     {self.cpf}\n"
        string += f"Número de identificação: {self.id}\n"
        string += f"Altura:                  {self.altura} cm\n"
        string += f"Peso:                    {self.peso} kg\n"
        string += f"Diagnostico:             {self.diagnostico}\n"
        string += f"Equipe:                  {self.equipe}\n"
        return string

    def associar(self, listaM, listaE):
        while True:
            a = input("Médico ou enfermeiro? ").lower()

            if a == "medico": ##
                medico = input("Digite o nome do médico. ").title()
                c = 0
                for j in range(len(listaM)):
                    if medico == listaM[j].getNome():
                        self.equipe["Médicos"].append(medico)
                        break
                    else: 
                        c += 1
                if c == 3:
                    print("Médico não encontrado.")

            elif a == "enfermeiro": ##
                enfermeiro = input("Digite o nome do enfermeiro. ").title()
                c = 0
                for j in range(len(listaE)):
                    if enfermeiro == listaE[j].getNome():
                        self.equipe["Enfermeiros"].append(enfermeiro)
                        break
                    else: 
                        c += 1
                if c == 3:
                    print("Enfermeiro não encontrado.")

            else: print("Comando invalido.")

            if input("Deseja associar mais uma pesso?(S/N) ").upper() == "N":
                break