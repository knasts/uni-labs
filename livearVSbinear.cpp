/* Написати функцію для пошуку елементу в масиві бінарним
алгоритмом, яка повертає індекс знайденого елементу або -1, якщо
такий елемент не знайдено*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <time.h>

using namespace std;

void sort_bubble(int arrayy[] , int N)
{
    for(int k = 0; k < N - 1; k++)
    {
        int swamps = 0;
        for(int n = 0; n < N - k - 1; n++)
        {
            if(arrayy[n] > arrayy[n + 1])
            {
                swap(arrayy[n], arrayy[n + 1]);
                swamps++;
            }
        }

        if(swamps == 0)
        {
            break;
        }
    }
}

int find_number_lineal(int number, int arrayy[], int N)
{
    for(int i = 0; i < N; i++)
    {
        if(arrayy[i] == number)
        {
            return i;
        }
    }
    return -1;
}


int find_number_binar(int number, int arrayy[], int N, int left_border, int right_border )
{
    if(left_border > right_border)
    {
       return -1;
    }

    int middle_num = (left_border + right_border) / 2;

    if(arrayy[middle_num] == number)
    {
        return middle_num;
    }
    else if(arrayy[middle_num] < number)
    {
        //left_border = middle_num + 1;
        return find_number_binar(number, arrayy, N, middle_num + 1, right_border);
    }
    else if(arrayy[middle_num] > number)
    {
        //right_border = middle_num + 1;
        return find_number_binar(number, arrayy, N, left_border, middle_num - 1);
    }
    return 0;
}


int main()
{
    int i;
    int number;
    int index_number_l, index_number_b;
    const int N = 1000;
    int arrayy[N];

    int left_border = 0;
    int right_border = N - 1;

    srand(time(0));
    for(i = 0; i < N; i++)
    {
        arrayy[i] = (rand() % 4001) - 2000;
    }

    sort_bubble(arrayy, N);
    int N_rand = (rand() % 999) + 1;
    if(arrayy[0] < arrayy[N_rand] && arrayy[N_rand] < arrayy[N_rand + 1])
    {
        cout << "Bubble sort was successful:)" << endl;
    }
    else
    {
        cout << "An error occurred during sorting:(" << endl;
    }

    double seconds_l = 0;
    double seconds_b = 0;


    for(i = 0; i < 80000; i++)
    {
        number = (rand() % 4001) - 2000;

        clock_t startTime = clock();
        index_number_l = find_number_lineal(number, arrayy, N);
        clock_t endTime = clock();
        seconds_l += double (endTime - startTime) / CLOCKS_PER_SEC;

        clock_t starttTime = clock();
        index_number_b = find_number_binar(number, arrayy, N, left_border, right_border);
        clock_t enddTime = clock();
        seconds_b += double (enddTime - starttTime) / CLOCKS_PER_SEC;
    }

    cout << "Number " << number << " is at the " << index_number_l << "nd position in the array (by the linear search)" << endl;
    cout << "Number " << number << " is at the " << index_number_b << "nd position in the array (by the binar search)" << endl;
    if(index_number_l == -1 || index_number_b == -1)
    {
        cout << "The array does not contain this number" << endl;
    }

    cout << "The runtime of searching for a number using a linear search - " << seconds_l << " seconds" << endl;
    cout << "The runtime of searching for a number using a binar search - " << seconds_b << " seconds" << endl;

    return 0;
}
