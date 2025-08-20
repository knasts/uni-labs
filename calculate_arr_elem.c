/* 14. Знайти середні значення і стандартні відхилення для елементів
масивів X (N), Y (M).*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void fill_array(int* array, int i)
{
    for(int j = 0; j < i; j++)
        {
            array[j] = (rand() % 20) + 1;
        }
}

void print_arr(int* array, int i)
{
    printf("Our array:  \n");
    for(int j = 0; j < i; j++)
    {

        printf(" %d", array[j]);

    }
    printf("\n");
}

void average_value(int* array, int i, float* value)
{
    int sum = 0;
    for(int j = 0; j < i; j++)
    {
        sum += array[j];
    }
    *value = (float)sum/i; //обчислюємо значення та зберігаємо через вказівник
}

void deviation_from_aver_value(int* array, int i, float* value)
{
    float sum = 0;
    float diff = 0;
    for(int j = 0; j < i; j++)
    {
        diff = (float)array[j] - *value;
        sum += pow(diff, 2);
    }
    *value = sqrt(sum/i);
}

int memory(int** array, int N)
{
    *array = (int*)malloc(N * sizeof(int));
}



int main()
{
    int N, M;
    float value1, value2;
    int* array1, * array2;
    srand(time(0));

    printf("Enter the size of the first array (positive integer please): ");
    scanf("%d", &N);
    printf("Enter the size of the second array (positive integer please): ");
    scanf("%d", &M);

    memory(&array1, N);
    memory(&array2, M);

    if(array1 == NULL || array2 == NULL)
    {
        printf("Memory allocation error");
        return -1;
    }

    fill_array(array1, N);
    fill_array(array2, M);

    print_arr(array1, N);
    print_arr(array2, M);
                //передаємо адресу змінної через & у функцію
    average_value(array1, N, &value1);
    average_value(array2, M, &value2);
    printf("Average element`s value in the first array: %0.1f \n", value1);
    printf("Average element`s value in the second array: %0.1f \n", value2);

    deviation_from_aver_value(array1, N, &value1);
    deviation_from_aver_value(array2, M, &value2);
    printf("Deviation from the average value in the first array: %0.1f \n", value1);
    printf("Deviation from the average value in the second array: %0.1f \n", value2);

    free(array1);
    free(array2);

    return 0;
}
