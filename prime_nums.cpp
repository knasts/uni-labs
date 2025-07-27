#include <iostream>
#include <cmath>
//Знайти 24-те, 37-ме, 46-те, 111-те за рахунком просте число.
using namespace std;

void isPrime(bool array_prime[], int N)
{
    for (int n = 2; n < N; n++)
    {
        if (array_prime[n] == true)
        {    //всі числа кратні n позначаються як непрості
            for (int i = n * n; i < N; i = i + n)
            {
                array_prime[i] = false;
            }
        }

    }
}

int main()
{
    int prime_num = 0;
    int n = 0;
    const int N = 1000;
    bool array_prime[N];
    const int goal = 112;
    int array_prime1[goal];

    for (int k = 0; k < N; k++)
    {
        array_prime[k] = true;
    }
    array_prime[0] = false;
    array_prime[1] = false;

    isPrime(array_prime, N);

    for (int t = 0; t <= 8000; t++)
    {
        for (int i = 2; i < N && prime_num < goal; i++)
        {
            if (array_prime[i] == true)
            {
                array_prime1[prime_num] = i;
                prime_num++;
            }
        }
    }

    cout << "24-th prime number is " << array_prime1[23] << endl;
    cout << "37-th prime number is " << array_prime1[36] << endl;
    cout << "46-th prime number is " << array_prime1[45] << endl;
    cout << "111-th prime number is " << array_prime1[100] << endl;

    return 0;
}
