class CategoriaProduto:
    def __init__(self, titulo):
        self.__titulo = titulo

    """Insira aqui os demais metodos ... """
    @property
    def titulo(self):
        return self.__titulo

    @titulo.setter
    def titulo(self, titulo):
        self.__titulo = titulo
