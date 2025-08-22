/* Реалізувати алгоритм знаходження простих чисел звичайним перебором
дільників, для цього створити функцію яка перевіряє одне число на
простоту: bool isPrime(int number) { ... }
Виконати задачу по варіанту, заміряти час роботи.
Знайти 24-те, 37-ме, 46-те, 111-те за рахунком просте число. */


#include <iostream>
#include <cmath>
#include <locale>
#include <windows.h>
#include <ctime>
#include <time.h>

using namespace std;

bool isPrime(int number)
{
    if(number == 0 || number == 1)
    {
        return false;
    }   //бо 2 вважається першим простим числом
    for(int k = 2; k <= sqrt(number); k++)
    {
        if((number % k) == 0 )
        {
            return false;
        }
    }
    return true;
}

int main()
{
    setlocale(LC_CTYPE, "ukr");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n = 0;
    int i = 0;
    const int goal = 112;
    int array_prime[goal];

    clock_t startTime = clock();
    for (int k = 0; k <= 8000; k++)
    {
        i = 0;
        n = 0;
        while (i <= goal)
        {
            if (isPrime(n) == true)
            {
                array_prime[i] = n;
                i = i + 1;
            }
            n++;
        }
    }

    clock_t endTime = clock();
    double seconds = (double (endTime - startTime));
    cout << "24-те за рахунком просте число це " << array_prime[23] << endl;
    cout << "37-ме за рахунком просте число це " << array_prime[36] << endl;
    cout << "46-те за рахунком просте число це " << array_prime[45] << endl;
    cout << "111-те за рахунком просте число це " << array_prime[110] << endl;
    cout << "Час виконання коду - " << seconds << " секунд" << endl;

    return 0;
}
