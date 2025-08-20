#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int option = 0;

    printf("��� ��������� ����� �������� �������� 1\n");
    printf("��� �������� 2 ��� ��������� �����:\n");
    scanf("%d", &option);

    const int one = 1;
    const int two = 2;

    if (option == one)
    {
        double a = 0.00045;
        double b = -0.00002;
        int c = 25;
        double fb = 0;
        double e = 1e-11;

        int variables = 0;

        printf("��� ����� ���� ������ �������� 1, \n");
        printf("���� �� ������ ��������� �� ������� �� �������������, �� ������ ����-��� ����� \n");
        scanf("%d", &variables);

        if (variables == one)
        {
            printf ("\n������ �������� a: ");
            scanf("%lf",&a);
            printf ("������ �������� b: ");
            scanf("%lf",&b);
            printf ("������ �������� c: ");
            scanf("%lf",&c);
        }
            fb = fabs(b);
            if (fb <= e)
            {
                printf("�������: ����� �� ���� �� �����\n");
                return 1;
            }

            else if (fb + c < e)
            {
                printf("�������: ����������� ����� ����� ����\n");
                return 1;
            }




        printf("x = (1+tg^2 a/2)^sqrt(|b|+c)\n");
        double x = pow(1 + pow(tan(a/2),2) , sqrt(abs(b)+ c));
        printf("��������� �������� �: %.2lf ;\n", x); //%.2f � ����� ������� ���� ����

        printf("y = 2ctg(a/|b|)\n");
        double y = 2 * ( cos(a/fb) / sin(a/fb) );
        printf("��������� �������� y: %.2lf ;\n", y);


    }

    else if (option == two)
    {
        float x = 0;
        float left_border = 0;
        float right_border = 0;
        float step = 0;
        float a1 = 0.7;

        printf("������ �������� ��� �������: \n");
        scanf("%f" , &left_border);
        printf("������ �������� ����� �������: \n");
        scanf("%f" , &right_border);
        printf("������ �������� �����: \n");
        scanf("%f" , &step);

        for (x = left_border ; x <= right_border + step/100 ; x = x + step)
        {

            if (fabs(x) <= step/100)
            {
                printf("x = 0 \n");
            }

            else if (x < 0)
            {
                printf("f(%.2f) = %.2f\n", x, (2 * a1 * log(fabs(x))));
            }

            else
            {
                float denominator = x + a1;
                if (denominator == 0)
                {
                    printf("�������: ��������� ������� ����");
                }
                printf("f(%.2f) = %.2f\n" , x , ((sqrt(pow(x , 3)/(x + a1))) - log(x)));
            }
        }

    }

/* �������� ���� ��������� */
    printf("\n\n");
    system("pause");
return 0;
}
