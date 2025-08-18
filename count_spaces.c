#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*�������� 1. ������ ���������� ����� n, ������� S1, .., Sn. ϳ��������� ��������
������� ������� ��������, �� ����� �����
*/

int main()
{
    int lenMax, len, max, count;
    char* temp;
    printf("Enter the maximum number of characters in the string: ");
    scanf("%d", &lenMax);
    getchar(); //��������� \n ���� scanf

    char *p = (char*) malloc(lenMax + 1); //�� �� \0 � ����
    if (p == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter characters: ");
    fgets(p, lenMax + 1, stdin); //fgets ����� enter � ���� \n
    len = strlen(p); //��������� �-� �������� �������
    temp = (char*) realloc(p, len + 1); //�� �� \0 � ����
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    p = temp;
    printf("You entered: %s\n", p);

    max = 0;
    count = 0;
    for(int i = 0; i < len; i++)
    {
        if(p[i] == ' ')
        {
            count++;
        }
        else
        {
            if(count > max)
            {
               max = count;
            }
            count = 0;
        }

    }
    if(count > max)
    {
        max = count;
    }
    printf("The biggest amount of free space in a row: %d\n", max);


    free(p);

    return 0;
}
