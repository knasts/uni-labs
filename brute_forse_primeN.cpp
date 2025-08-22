
#include <iostream>
#include <cmath>
#include <ctime>
#include <time.h>

using namespace std;

bool isPrime(int number)
{
    if(number == 0 || number == 1)
    {
        return false;
    }   
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
    cout << "24-nd prime number " << array_prime[23] << endl;
    cout << "37-nd prime number " << array_prime[36] << endl;
    cout << "46-nd prime number " << array_prime[45] << endl;
    cout << "111-nd prime number " << array_prime[110] << endl;
    cout << "total seconds - " << seconds << endl;

    return 0;
}


