// Copyright [2022] <Davi Menegaz Junkes>
#include <string>


class Aluno {
 public:
    Aluno() {}  // construtor
    ~Aluno() {}  // destrutor
    std::string devolveNome() {
        return nome;
    }
    int devolveMatricula() {
        return matricula;
    }
    void escreveNome(std::string nome_) {
        nome = nome_;
    }
    void escreveMatricula(int matricula_) {
        matricula = matricula_;
    }
 private:
    std::string nome;
    int matricula;
};


Aluno *turma_filtra(Aluno t[], int N, int menor_matr) {
    Aluno *tf;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < N; i++) {
        if (t[i].devolveMatricula() >= menor_matr) {
            count1++;
        }
    }

    tf = new Aluno[count1];

    for (int i = 0; i < N; i++) {
        if ((t[i].devolveMatricula() >= menor_matr) & (count1 > 0)) {
            tf[count2] = t[i];
            count1--;
            count2++;
        }
    }
    return tf;
}

int *turma_conta(Aluno t[], int N)
{
    int *c;
    c = new int[26]();

    for (int i = 0; i < N; i++)
    {
        c[t[i].devolveNome()[0] - 'A']++;
    }
    return c;
}



/*
    *** Importante ***

    A função 'main()' não deve ser escrita aqui, pois é parte do código dos testes e já está implementada

*/

