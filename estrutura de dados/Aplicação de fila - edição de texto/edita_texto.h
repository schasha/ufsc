// Copyright [2023] <Davi Menegaz Junkes>
#include <string>
#include "./array_queue.h"

structures::ArrayQueue<char> editaTexto(std::string texto) {
    structures::ArrayQueue<char> fila(500);
    for (size_t i = 0; i < texto.size(); i++) {
        if (texto[i] == '<') {
            fila.dequeue();
        } else if (texto[i] == '>') {
            fila.enqueue(fila.back());
          } else {
            fila.enqueue(texto[i]);
            }
    }
    return fila;
}

