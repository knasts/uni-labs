//���� ����� ����� ����� ������� 100. ������� �� ����� � ������ �� ����� �� 35 �� ������ ���� �������.

#include <iostream>
// ��������� ��������� ��������
#include <locale>
#include <windows.h>

using namespace std;

int main()
{
    //������. ���. ��������
    setlocale(LC_CTYPE, "ukr");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ��������� ����� ������� �� 100 ��������
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
            cout << item << " ����� �� 35" << endl;
        }
    }

    // �������� ����������� �-�� �������� ����� 35
    cout << "ʳ������ �������� ����� 35: " << num_less35 << endl;

    return 0;
}
