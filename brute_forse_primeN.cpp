/* Ðåàë³çóâàòè àëãîðèòì çíàõîäæåííÿ ïðîñòèõ ÷èñåë çâè÷àéíèì ïåðåáîðîì
ä³ëüíèê³â, äëÿ öüîãî ñòâîðèòè ôóíêö³þ ÿêà ïåðåâ³ðÿº îäíå ÷èñëî íà
ïðîñòîòó: bool isPrime(int number) { ... }
Âèêîíàòè çàäà÷ó ïî âàð³àíòó, çàì³ðÿòè ÷àñ ðîáîòè.
Çíàéòè 24-òå, 37-ìå, 46-òå, 111-òå çà ðàõóíêîì ïðîñòå ÷èñëî. */


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
    }   //áî 2 ââàæàºòüñÿ ïåðøèì ïðîñòèì ÷èñëîì
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

