//Ќаписати функц≥ю €ка за номером м≥с€ц€ визначаЇ к≥льк≥сть дн≥в у ньому.
//¬исокосний р≥к можна на враховувати.
//–оздрукувати таблицю дн≥в дл€ вс≥х зимових м≥с€ц≥в.

#include <iostream>
#include <locale>
#include <windows.h>

using namespace std;


int month_d(int month)
{
  int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month < 1 || month > 12)
    {
    cout << "“акого м≥с€ц€ не ≥снуЇ" << endl;
    return -1;
    }

  return month_days[month - 1];
}

int d = 1;
int j = 1;
int f = 1;

void calendar(int d , int j , int f)
{
    cout << "|" << d << ".12.24|  " <<  "|" << j << ".01.25|  " << "|" << f << ".02.25" << "|" << endl;
}

int main()
{
    setlocale(LC_CTYPE, "ukr");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int month = 0;
    cout << "¬вед≥ть номер м≥с€ц€ (в≥д 1 до 12) : " << endl;
    cin >> month;

    int this_month = month_d(month);
    cout << " ≥льк≥сть дн≥в в цьому м≥с€ц≥ :" << this_month << endl;


    cout << " √рудень:   " << "—≥чень:    " << "Ћютий:   " << endl;

    for (int k = 0 ; k < 28 ; ++k)
    {
        calendar(d , j , f);
        d = d + 1;
        j = j + 1;
        f = f + 1;
    }

    for (int k ; k < 31 ; ++ k)
    {
        cout << "|" << d << ".12.24|  " <<  "|" << j << ".01.25|" << endl;
        d = d + 1;
        j = j + 1;
        k = k + 1;
    }


    return 0;
}
