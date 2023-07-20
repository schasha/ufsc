from ave import Ave


class Canarinho(Ave):
    def __init__(self, tamanhoPasso: int, alturaVoo):
        super().__init__(tamanhoPasso, alturaVoo)

    def cantar(self):
        return super().produzirSom()
