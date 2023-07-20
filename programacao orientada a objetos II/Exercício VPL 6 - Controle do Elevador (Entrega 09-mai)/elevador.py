from abstractElevador import AbstractElevador


class Elevador(AbstractElevador):
    def __init__(self, andarAtual, totalAndaresPredio, capacidade, totalPessoas):
        self.__andarAtual = andarAtual
        self.__totalPessoas = totalPessoas
        self.__totalAndaresPredio = totalAndaresPredio
        self.__capacidade = capacidade

    # ElevadorJahNoTerreoException
    def descer(self) -> str:
    	self.andarAtual -= 1
    
    # ElevadorCheioException
    def entraPessoa(self) -> str:
        self.totalPessoas += 1
    
    # ElevadorJahVazioException
    def saiPessoa(self) -> str:
    	self.totalPessoas -= 1
    
    # ElevadorJahNoUltimoAndarException
    def subir(self) -> str:
    	self.andarAtual += 1
    
    @property
    def capacidade(self) -> int:
        return self.__capacidade

    @property
    def totalPessoas(self) -> int:
    	return self.__totalPessoas
    
    @property
    def totalAndaresPredio(self) -> int:
    	return self.__totalAndaresPredio
    
    @property
    def andarAtual(self) -> int:
    	return self.__andarAtual
    
    @totalAndaresPredio.setter
    def totalAndaresPredio(self, totalAndaresPredio: int):
    	self.__totalAndaresPredio = totalAndaresPredio
	
    @andarAtual.setter
    def andarAtual(self, andarAtual: int):
	    self.__andarAtual = andarAtual
	    
    @capacidade.setter
    def capacidade(self, capacidade):
	    self.__capacidade = capacidade
	    
    @totalPessoas.setter
    def totalPessoas(self, totalPessoas):
	    self.__totalPessoas = totalPessoas
