from mamifero import Mamifero


class Gato(Mamifero):
    def __init__(self, volumeSom = 2, tamanhoPasso: int = 2):
        super().__init__(volumeSom, tamanhoPasso)

    def miar(self):
        return super().produzirSom() + " SOM: MIAU"
