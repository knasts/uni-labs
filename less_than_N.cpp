//Дано масив цілих чисел розміром 100. Вивести всі числа з масиву які менші за 35 та знайти їхню кількість.

#include <iostream>
// підключаємо українську кирилицю
#include <locale>
#include <windows.h>

using namespace std;

int main()
{
    //підключ. укр. кирилицю
    setlocale(LC_CTYPE, "ukr");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // створюємо масив розміром на 100 елементів
    const int N = 100;
    int arr[N];
    int num_less35 = 0;
    srand(time(0));

	for (int each_element = 0; each_element < N; ++each_element )
    {
        arr[each_element] = 1 + rand() % 100;
        const int thirty_five = 35;

        int item = arr[each_element];
        if (item < thirty_five)
        {
            num_less35 = num_less35 + 1;
            cout << item << " менше за 35" << endl;
        }
    }

    // виводимо користувачу к-ть елементів менше 35
    cout << "Кількість елементів менше 35: " << num_less35 << endl;

    return 0;
}
