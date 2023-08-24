// Copyright [2022] <Davi Menegaz Junkes>
#include <string>
#include "./array_stack.h"

bool verificaChaves(std::string trecho_programa) {
    bool resposta = true;
    int  tamanho  = trecho_programa.length();
    structures::ArrayStack<char> pilha(500);
    char caracter;

    for (int i = 0; i < tamanho; i++) {
        caracter = trecho_programa[i];
        if (caracter == '{') {
            pilha.push('{');
        }
        if (caracter == '}') {
            if (pilha.empty() || pilha.top() == '}') {
                resposta = false;
                break;
            }
            if (pilha.top() == '{') {
                pilha.pop();
            }
        }
    }
    return resposta;
}

