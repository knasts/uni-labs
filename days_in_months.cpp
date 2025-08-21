//�������� ������� ��� �� ������� ����� ������� ������� ��� � �����.
//���������� �� ����� �� �����������.
//������������ ������� ��� ��� ��� ������� ������.

#include <iostream>
#include <locale>
#include <windows.h>

using namespace std;


int month_d(int month)
{
  int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month < 1 || month > 12)
    {
    cout << "������ ����� �� ����" << endl;
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
    cout << "������ ����� ����� (�� 1 �� 12) : " << endl;
    cin >> month;

    int this_month = month_d(month);
    cout << "ʳ������ ��� � ����� ����� :" << this_month << endl;


    cout << " �������:   " << "ѳ����:    " << "�����:   " << endl;

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
