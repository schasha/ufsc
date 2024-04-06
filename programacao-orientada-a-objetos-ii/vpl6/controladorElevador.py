from abstractControladorElevador import AbstractControladorElevador
from comandoInvalidoException import ComandoInvalidoException
from elevador import Elevador
from elevadorCheioException import ElevadorCheioException
from elevadorJahNoTerreoException import ElevadorJahNoTerreoException
from elevadorJahNoUltimoAndarException import ElevadorJahNoUltimoAndarException
from elevadorJahVazioException import ElevadorJahVazioException

class ControladorElevador(AbstractControladorElevador):
    def __init__(self):
        pass

    @property
    def elevador(self) -> Elevador:
        return self.__elevador
    
    def inicializarElevador(self, andarAtual: int, totalAndaresPredio: int, capacidade: int, totalPessoas: int):
        for i in (andarAtual, totalAndaresPredio, capacidade, totalPessoas):
            if type(i) != int or i < 0:
                raise ComandoInvalidoException
        if andarAtual >= totalAndaresPredio:
            raise ComandoInvalidoException
        if totalPessoas > capacidade:
            raise ComandoInvalidoException
        self.__elevador = Elevador(andarAtual, totalAndaresPredio, capacidade, totalPessoas) 

    def subir(self) -> str:
        if self.elevador.andarAtual >= self.elevador.totalAndaresPredio:
            raise ElevadorJahNoUltimoAndarException
        self.elevador.subir()
    
    def descer(self) -> str:
        if self.elevador.andarAtual <= 0:
            raise ElevadorJahNoTerreoException
        self.elevador.descer()

    def entraPessoa(self) -> str:
        if self.elevador.totalPessoas >= self.elevador.capacidade:
            raise ElevadorCheioException
        self.elevador.entraPessoa()
	
    def saiPessoa(self) -> str:
        if self.elevador.totalPessoas <= 0:
            raise ElevadorJahVazioException
        self.elevador.saiPessoa()

