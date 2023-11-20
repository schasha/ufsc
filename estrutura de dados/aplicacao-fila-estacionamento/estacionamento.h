// Copyright [2023] <Davi Menegaz Junkes>

/*
    *** Importante ***

    O código de fila em vetor está disponível internamente (não precisa de implementação aqui)

*/



void retira_veiculo(structures::ArrayQueue<int> *f, int k) {
    int dequeued;

    for (int i = 1; i < k + 1; i ++) {
        dequeued = f->dequeue();
        if (i != k) {
            f->enqueue(dequeued);
        }
    }
}


void mantenha_veiculo(structures::ArrayQueue<int> *f, int k) {
    int count = 1;
    int dequeued;
  
    while (static_cast<int>(f->size()) != 1) {
        dequeued = f->dequeue();
        count++;
        if (count == k + 1) {
            f->enqueue(dequeued);
        }
    }
}




/*
    *** Importante ***

    A função 'main()' não deve ser escrita aqui, pois é parte do código dos testes e já está implementada

*/

