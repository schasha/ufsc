"""Universidade Federal de Santa Catarina.
   CTC - Centro Tecnologico - http://ctc.ufsc.br
   INE - Departamento de Informatica e Estatistica - http://inf.ufsc.br
"""

class Ordenacao():

    def __init__(self, array_para_ordenar = []):
        """Recebe o array com o conteudo a ser ordenado"""
        self.array = array_para_ordenar
        

    def ordena(self):
        """Realiza a ordenacao do conteudo do array recebido no construtor"""
        maior = 0
        for i in self.array:
            if i > maior:
                maior = i

        sorted_array = []
        sorted_array.append(self.array.pop(self.array.index(maior)))
        for i in self.array:
            for j in sorted_array:
                if i <= j:
                    sorted_array.insert(sorted_array.index(j), i)
                    break

        self.array = sorted_array

        return self.toString()

    def toString(self):
        """Converte o conteudo do array em String formatado
           Exemplo: 
           Para o conteudo do array: [1,2,3,4,5]
           Retorna: "1,2,3,4,5"
           @return String com o conteudo do array formatado
        """
        array = self.array
        string = ''
        for i in array:
            string = string + f"{i},"
        string = string.strip(",")
        
        return string