from pessoa import Pessoa

class Medico(Pessoa):
    def __init__(self, nome, telefone, cpf, salario, area, pacientes):
        super().__init__(nome, telefone, cpf)
        self.salario = salario
        self.area = area
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
        string += f"Area:                    {self.area}\n"
        string += f"Pacientes:               {self.pacientes}\n"
        return string   

    def associar(self, paciente):
        self.pacientes.append(paciente)


m1 = Medico("Matheus", "4899151238", "125609342", "20000", "Dermatologia", [])
m2 = Medico("Pedro", "4893518234", "745634343", "20000", "Cardiologia", [])
m3 = Medico("Isabela", "4891266579", "165348323", "20000", "Neurologia", [])