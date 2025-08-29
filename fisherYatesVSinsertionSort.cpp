/* Написати функцію для сортування вставками за критерієм залишку від
цілочисельного ділення суми всіх цифр числа на 10 у порядку зростання (напр.
93 < 25, адже 2 < 7), при рівності - спочатку менше за значенням. */

#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void fisher_yates_shuffling(int arrayy[], int N)
{
    int k;
    int n;
    for(k = N - 1; k != 0; k = k - 1)
    {       //від 1 до k
        n = (rand() % k) + 1;
        swap(arrayy[n], arrayy[k]);
    }

}

int suma_num(int num)
{
    int d;
    int suma = 0;
    for(num; num != 0; num = num / 10) //знаходимо суму всіх чисел числа
        {
            d = num % 10;
            suma += d;
        }
    return suma % 10;
}

void arrayy_insertion_sorting(int arrayy[], int N)
{
    int n, num, num_l, suma_n, suma_n_left, j;
    for(n = 1; n < N; n++) //проходимо по всім елементам масиву
    {
        num = arrayy[n];
        suma_n = suma_num(num);

        j = n;
        while(j > 0)
        {
            num_l = arrayy[j - 1];
            suma_n_left = suma_num(num_l);
            if (suma_n == suma_n_left)
            {
                if(num < num_l)
                {
                    swap(num, num_l);
                }
            }
            if(suma_n_left > suma_n)
            {
                arrayy[j] = arrayy[j - 1];
                j--;
            }
            else
            {
                break;
            }

        }
        arrayy[j] = num;
    }

}

int main()
{
    int i;
    const int N = 200;
    int arrayy[N];
    srand(time(0));

    for(i = 0; i < N; i++)
    {
        arrayy[i] = i + 1;
    }

    fisher_yates_shuffling(arrayy, N);

    arrayy_insertion_sorting(arrayy, N);
                    //випадкове число від 20 до 199
    int N_rand = (rand() % 180) + 20;
    int suma_zero = suma_num(arrayy[0]);
    int suma_rand = suma_num(arrayy[N_rand]);
    if(suma_zero < suma_rand)
    {
        cout << "insertion sort was successful:)";
    }
    else
    {
        cout << "it seems that something went wrong...";
    }

    return 0;
}
