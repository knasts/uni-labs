
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 

bool are_negative(int* array, int N)
{
    int mid = N / 2;
    if(N != 1)
    {                                                   
        return are_negative(array, mid) && are_negative(array + mid, N - mid);
    }
    return array[0] < 0; 
}

int main()
{
    int N, i;
    bool answ;
    printf("Enter dimension of the array: ");
    scanf("%d", &N);

    int* arrayy = (int *)malloc(N * sizeof(int)); 
    if(arrayy == NULL)
    {
        printf("Memory allocation error\n");
        return -1;
    }

    srand(time(0));
    for(i = 0; i < N; i++)
    {
        arrayy[i] = (rand() % 21) - 10;
    }

    printf("Our array: ");
    for(i = 0; i < N; i++)
    {
        printf(" %d", arrayy[i]);
    }
    printf("\n");

    answ = are_negative(arrayy, N); 
    if(answ)
    {
        printf("ALL elements in our array are negative");
    }
    else
    {
        printf("All elements in our array are NOT negative");
    }

    free(arrayy);
    return 0;
}

