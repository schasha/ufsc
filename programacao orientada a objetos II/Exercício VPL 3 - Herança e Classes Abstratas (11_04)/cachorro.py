from mamifero import Mamifero


class Cachorro(Mamifero):
    def __init__(self, volumeSom = 3, tamanhoPasso: int = 3):
        super().__init__(volumeSom, tamanhoPasso)

    def latir(self):
        return super().produzirSom() + " SOM: AU"
