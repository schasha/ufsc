#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdlib.h>

FILE* out;
sem_t semA, semB;


void *thread_a(void *args) {
    for (int i = 0; i < *(int*)args; ++i) {
        sem_wait(&semA);
	//      +---> arquivo (FILE*) destino
	//      |    +---> string a ser impressa
	//      v    v
        fprintf(out, "A");
        // Importante para que vocês vejam o progresso do programa
        // mesmo que o programa trave em um sem_wait().
        fflush(stdout);
        sem_post(&semB);
    }
    return NULL;
}

void *thread_b(void *args) {
    for (int i = 0; i < *(int*)args; ++i) {
        sem_wait(&semB);
        fprintf(out, "B");
        fflush(stdout);
        sem_post(&semA);
    }
    return NULL;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Uso: %s [ITERAÇÕES]\n", argv[0]);
        return 1;
    }
    int iters = atoi(argv[1]);
    srand(time(NULL));
    out = fopen("result.txt", "w");
    // semaforos init
    sem_init(&semA, 0, 1);
    sem_init(&semB, 0, 1);

    pthread_t ta, tb;

    // Cria threads
    pthread_create(&ta, NULL, thread_a, &iters);
    pthread_create(&tb, NULL, thread_b, &iters);

    // Espera pelas threads
    pthread_join(ta, NULL);
    pthread_join(tb, NULL);

    // semaforos destroy
    sem_destroy(&semA);
    sem_destroy(&semB);

    //Imprime quebra de linha e fecha arquivo
    fprintf(out, "\n");
    fclose(out);
  
    return 0;
}
