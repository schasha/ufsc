#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>

// Lê o conteúdo do arquivo filename e retorna um vetor E o tamanho dele
// Se filename for da forma "gen:%d", gera um vetor aleatório com %d elementos
//
// +-------> retorno da função, ponteiro para vetor malloc()ado e preenchido
// | 
// |         tamanho do vetor (usado <-----+
// |         como 2o retorno)              |
// v                                       v
double* load_vector(const char* filename, int* out_size);

// Avalia se o prod_escalar é o produto escalar dos vetores a e b. Assume-se
// que ambos a e b sejam vetores de tamanho size.
void avaliar(double* a, double* b, int size, double prod_escalar);

void* dotProductI(void*);

typedef struct {
    double* a;
    double* b;
    double* results;
    int n_loops;
    int n_threads;
    int size;
    int thread_number;
}vecInfo;


int main(int argc, char* argv[]) {
    srand(time(NULL));

    //Temos argumentos suficientes?
    if(argc < 4) {
        printf("Uso: %s n_threads a_file b_file\n"
               "    n_threads    número de threads a serem usadas na computação\n"
               "    *_file       caminho de arquivo ou uma expressão com a forma gen:N,\n"
               "                 representando um vetor aleatório de tamanho N\n", 
               argv[0]);
        return 1;
    }
  
    //Quantas threads?
    int n_threads = atoi(argv[1]);
    if (!n_threads) {
        printf("Número de threads deve ser > 0\n");
        return 1;
    }
    //Lê números de arquivos para vetores alocados com malloc
    int a_size = 0, b_size = 0;
    double* a = load_vector(argv[2], &a_size);
    if (!a) {
        //load_vector não conseguiu abrir o arquivo
        printf("Erro ao ler arquivo %s\n", argv[2]);
        return 1;
    }
    double* b = load_vector(argv[3], &b_size);
    if (!b) {
        printf("Erro ao ler arquivo %s\n", argv[3]);
        return 1;
    }
    
    //Garante que entradas são compatíveis
    if (a_size != b_size) {
        printf("Vetores a e b tem tamanhos diferentes! (%d != %d)\n", a_size, b_size);
        return 1;
    }

    //Calcula produto escalar
    int n_loops = a_size/n_threads;
    if (a_size % n_threads) n_loops++;

    double* results = (double*) malloc(sizeof(double)*n_threads); //Parcela de cada thread
    vecInfo vectors_array[n_threads];

    //threads
    pthread_t threads[n_threads];
    for (int i = 0; i < n_threads; i++) {
        vecInfo tmp = {a, b, results, n_loops, n_threads, a_size, i};
        vectors_array[i] = tmp;
        pthread_create(&threads[i], NULL, dotProductI, (void*)&vectors_array[i]);
    }
    for (int i = 0; i < n_threads; i++) {
        pthread_join(threads[i], NULL);
    }
     
    double result;
    for (int i = 0; i < n_threads; i++) { 
        result += results[i];
    }

    //    +---------------------------------+
    // ** | IMPORTANTE: avalia o resultado! | **
    //    +---------------------------------+
    avaliar(a, b, a_size, result);

    //Libera memória
    free(a);
    free(b);
    free(results);

    return 0;
}

void* dotProductI(void* arg){
    vecInfo* vectors = ((vecInfo *)arg);

    double result; 

    for (int i = 0; i < vectors->n_loops; i++) {
        int target = i*vectors->n_threads + vectors->thread_number; //counts by n_threads's n_loops times + thread_number offset
        if (target >= vectors->size) {
            vectors->results[vectors->thread_number] = result;
            pthread_exit(NULL);
        }

        result += vectors->a[target] * vectors->b[target];
    }
    vectors->results[vectors->thread_number] = result;

    pthread_exit(NULL);
} 
