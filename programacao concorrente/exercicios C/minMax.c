#include <stdlib.h>
#include <stdio.h>

typedef struct MinMax
{
    int min;
    int max;
} MinMax;

MinMax *getMinMax(int * array, const int SIZE) {
    MinMax minmax;
    MinMax *pminmax = (MinMax*) malloc(sizeof(MinMax));
    pminmax = &minmax;

    minmax.min = array[0];
    minmax.max = array[0];
    
    for (int i = 1; i < SIZE; i++) {
        if (array[i] > minmax.max) {
            minmax.max = array[i];
        }

        if (array[i] < minmax.min) {
            minmax.min = array[i];
        }
    }
    return pminmax;
}


int main(void) {
    int array[10] = {2, 3, 4 ,1 ,6 ,12 ,32 ,8 ,7 ,10};
    MinMax *minmax;

    minmax = getMinMax(array, 10);

    printf("%d, %d\n", minmax->min, minmax->max);

    return 0;
}
