from pessoa import Pessoa

class Enfermeiro(Pessoa):
    def __init__(self, nome, telefone, cpf, salario, pacientes):
        super().__init__(nome, telefone, cpf)
        self.salario = salario
        self.pacientes = pacientes

    def getNome(self):
        return self.nome
    def getPacientes(self):
        return self.pacientes

    def __str__(self):
        string = ""
        string += f"Nome:                    {self.nome}\n"
        string += f"Telefone:                {self.telefone}\n"
        string += f"CPF:                     {self.cpf}\n"
        string += f"Salario:                 {self.salario} reais\n"
        string += f"Pacientes:               {self.pacientes}\n"
        return string

    def associar(self, paciente):
        self.pacientes.append(paciente)

e1 = Enfermeiro("Joao", "4899583218", "42134690", "7000", [])
e2 = Enfermeiro("Clara", "4891345235", "64539199", "7000", [])
e3 = Enfermeiro("Maria", "4894873472", "287043119", "7000", [])