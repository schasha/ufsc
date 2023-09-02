#include <stdio.h>
#include <stdlib.h>

//Lê os elementos do teclado e os coloca em arr. Size possui o tamanho do vetor
void inputArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

//Imprime o conteúdo do vetor arr com tamanho size
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Função que compara dois inteiros. A função retorna a diferença entre o primeiro e o segundo
int sortAscending(int* num1, int* num2) {
    return *num1 - *num2;
}

//Função que compara dois inteiros. A função retorna a diferença entre o segundo e o primeiro
int sortDescending(int* num1, int* num2) {
    return *num2 - *num1;
}

//Função que realizada a ordenação. O terceiro argumento é um ponteiro para 
//função que realiza a comparação entre dois inteiros do vetor (funções sortAscending ou sortDescending)
void sort(int* arr, int size, int (*compare)(int *, int *)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compare(&arr[j], &arr[j + 1]) > 0 ) {
                swap(&arr[j], &arr[j + 1]); 
            }
        }
    }
}

int main()
{
    int size;
    int *arr = (int *)malloc(size * sizeof(int));

    //Input array size and elements.
    printf("Enter array size: ");
    scanf("%d", &size);
    printf("Enter elements in array: ");
    inputArray(arr, size);
    printf("\n\nElements before sorting: ");
    printArray(arr, size);
    
    // Sort and print sorted array in ascending order.
    printf("\n\nArray in ascending order: ");
    sort(arr, size, sortAscending);
    printArray(arr, size);

    // Sort and print sorted array in descending order.
    printf("\nArray in descending order: ");
    sort(arr, size, sortDescending);
    printArray(arr, size);
    printf("\n");

    free(arr);

    return 0;
}
