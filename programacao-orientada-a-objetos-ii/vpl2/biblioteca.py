from livro import Livro


class Biblioteca:
    def __init__(self):
        self.__livros = []

    def incluirLivro(self, livro: Livro):
        if isinstance(livro, Livro):
            if livro not in self.__livros:
                self.__livros.append(livro)

    def excluirLivro(self, livro: Livro):
        if isinstance(livro, Livro):
            if livro in self.__livros:
                self.__livros.remove(livro)

    @property
    def livros(self):
        return self.__livros

