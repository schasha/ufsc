class Pessoa:
    def __init__(self, nome, telefone, cpf):
        self.nome = nome
        self.telefone = telefone
        self.cpf = cpf

    def getNome(self):
        return self.nome
    def getTelefone(self):
        return self.telefone
    def getCpf(self):
        return self.cpf
    
    def setNome(self, i):
        self.nome = i
    def setTelefone(self, i):
        self.telefone = i
    def setCpf(self, i):
        self.cpf = i