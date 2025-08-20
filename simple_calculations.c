#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int option = 0;

    printf("Для виконання першої програми натисніть 1\n");
    printf("або натисніть 2 для виконання другої:\n");
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

        printf("Для вводу своїх змінних натисніть 1, \n");
        printf("якщо ви хочете працювати із змінними за замовчуванням, то введіть будь-яке число \n");
        scanf("%d", &variables);

        if (variables == one)
        {
            printf ("\nВведіть значення a: ");
            scanf("%lf",&a);
            printf ("Введіть значення b: ");
            scanf("%lf",&b);
            printf ("Введіть значення c: ");
            scanf("%lf",&c);
        }
            fb = fabs(b);
            if (fb <= e)
            {
                printf("Помилка: ділити на нуль не можна\n");
                return 1;
            }

            else if (fb + c < e)
            {
                printf("Помилка: підкореневий вираз менше нуля\n");
                return 1;
            }




        printf("x = (1+tg^2 a/2)^sqrt(|b|+c)\n");
        double x = pow(1 + pow(tan(a/2),2) , sqrt(abs(b)+ c));
        printf("Розрахуємо значення х: %.2lf ;\n", x); //%.2f з двома знаками після коми

        printf("y = 2ctg(a/|b|)\n");
        double y = 2 * ( cos(a/fb) / sin(a/fb) );
        printf("Розрахуємо значення y: %.2lf ;\n", y);


    }

    else if (option == two)
    {
        float x = 0;
        float left_border = 0;
        float right_border = 0;
        float step = 0;
        float a1 = 0.7;

        printf("Введіть значення лівої границі: \n");
        scanf("%f" , &left_border);
        printf("Введіть значення правої границі: \n");
        scanf("%f" , &right_border);
        printf("Введіть значення кроку: \n");
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
                    printf("Помилка: знаменник дорівнює нулю");
                }
                printf("f(%.2f) = %.2f\n" , x , ((sqrt(pow(x , 3)/(x + a1))) - log(x)));
            }
        }

    }

/* Затримка вікна виведення */
    printf("\n\n");
    system("pause");
return 0;
}
