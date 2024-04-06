import PySimpleGUI as sg

class CalcIMC():
    def __init__(self,):
        self.layout = [
            [sg.Text('Digite seus dados para o calculo do IMC')],
            [sg.Text('Peso', size=(15, 1)), sg.InputText()],
            [sg.Text('Altura', size=(15, 1)), sg.InputText()],
            [sg.Text('Seu IMC eh:'), sg.Text('', key='IMC')],
            [sg.Submit('Calcular')]
                    ]
        self.window = sg.Window("Calculadora de IMC", self.layout, font=('helvetica', 15))

    def run(self):
        rodando = True
        while rodando:
            event, values = self.window.read()
            print(values)
            if event == sg.WIN_CLOSED:
                rodando = False
            elif event == 'Calcular':
                IMC = self.calculo(float(values[0]), float(values[1]))
                self.window.Element('IMC').update(IMC)
    
    def calculo(self, peso, altura):
        return peso/altura**2
    
c = CalcIMC()
c.run()