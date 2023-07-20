from animal import Animal, abstractmethod


class Ave(Animal):
    @abstractmethod
    def __init__(self, tamanhoPasso: int, alturaVoo):
        super().__init__(tamanhoPasso)
        self.__alturaVoo = alturaVoo

    @property
    def alturaVoo(self):
        return self.__alturaVoo
    
    @alturaVoo.setter
    def alturaVoo(self, alturaVoo):
        self.__alturaVoo = alturaVoo

    def mover(self):
        return f"ANIMAL: DESLOCOU {self.__tamanhoPasso} VOANDO"
    
    def produzirSom(self):
        return "AVE: PRODUZ SOM: PIU"
    

