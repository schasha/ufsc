from animal import Animal, abstractmethod


class Mamifero(Animal): 
    @abstractmethod
    def __init__(self, volumeSom, tamanhoPasso: int,):
        super().__init__(tamanhoPasso)
        self.__volumeSom = volumeSom

    @property
    def volumeSom(self):
        return self.__volumeSom
    
    @volumeSom.setter
    def volumeSom(self, volumeSom):
        self.__volumeSom = volumeSom

    def produzirSom(self):
        return f"MAMIFERO: PRODUZ SOM: {self.__volumeSom}"
