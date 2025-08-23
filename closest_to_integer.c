#include <stdio.h>
#include <math.h>

float calculation(float x, int k)
{
    int two = 2 * k;
    int three = 3 * k; //math formula
    float number = exp(cos(pow(x, two))) * sin(pow(x,three));
    return number;
}

int main()
{
    int n, k;
    float x, num, number;
    float less_num = 0;
    float less_abs = 0.6;
    float current_abs;
    const int ten = 10;

    printf("Enter the value of n (can`t be less than 1):\n");
    scanf("%d", &n);
    printf("Enter the value of x: \n");
    scanf("%f", &x);

    if(n < 1)
    {
        printf("Eror: the value of n can`t be less than 1\n");
        while(n < 1)
        {
            printf("Try again: \n");
            printf("Enter the value of n (can`t be less than 1):\n");
            scanf("%d", &n);
        }
    }

    for(k = 1; k <= n; k++)
    {
        number = calculation(x, k);
        num = roundf(number);
        current_abs = fabs(num - number);
        if(current_abs < less_abs)
        {
            less_num = number;
            less_abs = current_abs;
        }
    }

    printf("Our number closest to an integer: %.4f \n" , less_num);
    return 0;
}

