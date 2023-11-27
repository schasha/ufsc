#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <iostream>

void quickSort(int* A, int p, int r);
void heapSort(int* A, int N);
int* randArray(int N);
void copyArray(int* source, int* destination, int size);


int main() {
    using namespace std;

    int* aq1000 = randArray(1000);
    int* aq5000 = randArray(5000);
    int* aq10000 = randArray(10000);
    int* aq50000 = randArray(50000);
    int* aq100000 = randArray(100000);

    int* ah1000 = new int[1000]; 
    int* ah5000 = new int[5000];
    int* ah10000 = new int[10000]; 
    int* ah50000 = new int[50000];
    int* ah100000 = new int[100000];

    copyArray(aq1000, ah1000, 1000);
    copyArray(aq5000, ah5000, 5000);
    copyArray(aq10000, ah10000, 10000);
    copyArray(aq50000, ah50000, 50000);
    copyArray(aq100000, ah100000, 100000);

    auto start = chrono::high_resolution_clock::now();
    quickSort(aq1000, 0, 999);
    auto end = chrono::high_resolution_clock::now();
    double duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "quickSort 1000: " << duration << " ms\n";

    start = chrono::high_resolution_clock::now();
    quickSort(aq5000, 0, 4999);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "quickSort 5000: " << duration << " ms\n";
    
    start = chrono::high_resolution_clock::now();
    quickSort(aq10000, 0, 9999);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "quickSort 10000: " << duration << " ms\n";

    start = chrono::high_resolution_clock::now();
    quickSort(aq50000, 0, 49999);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "quickSort 50000: " << duration << " ms\n";

    start = chrono::high_resolution_clock::now();
    quickSort(aq100000, 0, 99999);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "quickSort 100000: " << duration << " ms\n";

    start = chrono::high_resolution_clock::now();
    heapSort(ah1000, 1000);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "heapSort 1000: " << duration << " ms\n";

    start = chrono::high_resolution_clock::now();
    heapSort(ah5000, 5000);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "heapSort 5000: " << duration << " ms\n";

    start = chrono::high_resolution_clock::now();
    heapSort(ah10000, 10000);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "heapSort 10000: " << duration << " ms\n";

    start = chrono::high_resolution_clock::now();
    heapSort(ah50000, 50000);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "heapSort 50000: " << duration << " ms\n";

    start = chrono::high_resolution_clock::now();
    heapSort(ah100000, 100000);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "heapSort 100000: " << duration << " ms\n";

    return 0;
}

void copyArray(int* source, int* destination, int size) {
    for (int i = 0; i < size; ++i)
        destination[i] = source[i];
}

int* randArray(int N) {
    int* array = new int[N];
    for (int i = 0; i < N; i++)
        array[i] = std::rand();

    return array;
}

int particione(int *A, int p, int r) {
    int i, x, tmp;

    x = A[r];
    i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }

    tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp;

    return i + 1;
}

void quickSort(int* A, int p, int r) {
    int q;

    if (p < r) {
        q = particione(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

void heapify(int* A, int N, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int tmp;
 
    if (l < N && A[l] > A[largest])
        largest = l;
 
    if (r < N && A[r] > A[largest])
        largest = r;
 
    if (largest != i) {
        tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
 
        heapify(A, N, largest);
    }
}
 
void heapSort(int* A, int N) {
    int tmp;
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(A, N, i);
 
    for (int i = N - 1; i > 0; i--) {
        tmp = A[0];
        A[0] = A[i];
        A[i] = tmp;
 
        heapify(A, i, 0);
    }
}
