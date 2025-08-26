#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int N, mid, m;
    printf("Enter the dimensions of the array: (must be even) ");
    scanf("%d", &N); 

    while(N % 2)
    {
        printf("Error!\n");
        printf("Enter the dimensions of the array: (must be even) ");
        scanf("%d", &N);
    }

    float* array = (float*)malloc(N * sizeof(float)); 
    if (array == NULL) 
    {
        printf("Memory allocation error\n");
        return 1;
    }

    srand(time(0));
    for(int i = 0; i < N; i++)
    {
        array[i] = (rand() % 151) + (rand() / (float)RAND_MAX);
    }

    mid = N/2;
    for(int k = 0, m = mid; k < mid; k++, m++)
    {
        printf("element %d = %.2f, element %d = %.2f\n", k , array[k], m, array[m]);
    }
    free(array);
    return 0;
}

