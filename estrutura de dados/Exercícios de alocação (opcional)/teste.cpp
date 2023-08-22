// Copyright [2022] <Davi Menegaz Junkes>
#include <iostream>
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

    for (int i = 0; i < count1; i++) {
        if (t[i].devolveMatricula() >= menor_matr) {
            tf[i] = t[i];
        }
    }
    return tf;
}

int *turma_conta(Aluno t[], int N) {
    int *c;
    c = new int[26]();

    for (int i = 0; i < N; i++) {
        for (char k = 'A'; i <='Z'; k++) {
            if (t[i].devolveNome()[0] = k) {
                c[k - 'A']++;
            }
        }
    }
    return c;
}


Aluno *turma(std::string nomes[], int matriculas[], int N) {
    Aluno *t = new Aluno[N];
    for (int i = 0; i < N; i++) {
        t[i].escreveNome(nomes[i]);
        t[i].escreveMatricula(matriculas[i]);
    }
    return t;
}

int main() {
    std::string nomes1[6] =
        {"Alana", "Arthur", "Lorena", "Maria", "Pedro", "Olivia"};
    int matriculas1[6] = {11, 22, 33, 44, 55};
    int N1 = 6;

    std::string nomes2[3] = {"Maria", "Pedro", "Olivia"};
    int matriculas2[3] = {33, 44, 55};
    int N2 = 3;

    int matriculas3[3] = {55};
    Aluno *t = turma(nomes1, matriculas1, 6);
    
    Aluno *tf = turma_filtra(t, 6, 22);

    for (int i = 0; i < 6; i++) {
        std::cout << tf[i].devolveNome() << "\n";
    }
    return 0;
}
