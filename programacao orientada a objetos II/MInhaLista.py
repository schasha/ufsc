class Lista():
    def __init__(self, dados: tuple):
        self.dados = dados

    def __str__(self):
        return str(self.dados)

    def __getitem__(self, key):
        return self.dados[key]

    def __setitem__(self, key, value):
        if key != -1:
            self.dados = *self.dados[:key], value, *self.dados[key + 1:]
        else:
            self.dados = *self.dados[:key], value

    def index(self, item):
        found = False
        for i, element in enumerate(self.dados):
            if element == item:
                found = True
                return i
        if not found:
            raise ValueError("Item não achado.")

    def append(self, dado):
        self.dados = *self.dados, dado

    def insert(self, key, value):
        if key != -1:
            self.dados = *self.dados[:key], value, *self.dados[key:]
        else:
            self.dados = *self.dados[:], value

    def pop(self, index = -1):
        popped = self.dados[index]
        if index != -1:
            self.dados = *self.dados[:index], *self.dados[index + 1:]
        else:
            self.dados = *self.dados[:index],
        return popped

    def remove(self, item):
        index = self.dados.index(item)
        self.dados = *self.dados[:index], *self.dados[index + 1:]

    def reverse(self):
        reverso = self.dados[::-1]
        self.dados = reverso

    def sort(self):
        max_d = max(self.dados)
        sorted_list = max_d,
        for i in self.dados:
            for j in sorted_list:
                if i < j:
                    sorted_list = *sorted_list[:sorted_list.index(j)], i, *sorted_list[sorted_list.index(j):]
                    break
        self.dados = sorted_list
