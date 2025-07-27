#include <stdio.h>
#include <ctype.h>
#include <ctime>
#include <stdlib.h>
/*Завдання 2. Дано файл F, компоненти якого є цілими числами. Жоден з
компонентів файлу не дорівнює нулю. Числа в файлі йдуть в такому порядку: десять
від’ємних, десять додатних, десять від’ємних, десять додатних і т.д. Переписати
компоненти файлу F у файл G так, щоб у файлі G числа йшли в наступному порядку:
п’ять від’ємних, п’ять додатних, п’ять від’ємних, п’ять додатних і т.д. */

void filling_in_old(int amount)
{
	FILE* fout;
	errno_t err = fopen_s(&fout, "labaa.txt", "w");
	if (err != 0)
	{
		printf("file opening eror:/ \n");
		return;
	}

	for (int j = 0; j < amount; j++)
	{
		for (int i = 0; i != 10; i++)
		{
			int num = (rand() % 20) - 21;
			fprintf(fout, "%d ", num);
		}
		for (int k = 0; k != 10; k++)
		{
			int num = rand() % 20;
			fprintf(fout, "%d ", num);
		}
	}
	fclose(fout);
}

void filling_in_new(int amount)
{
	FILE* fin;
	errno_t err = fopen_s(&fin, "labaa.txt", "r");
	if (err != 0)
	{
		printf("file opening eror:/ \n");
		return;
	}

	FILE* fout;
	err = fopen_s(&fout, "resultss.txt", "w");
	if (err != 0)
	{
		printf("file opening eror:/ \n");
		return;
	}

	int number = 0;

	for (int j = 0; j < amount; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (fscanf(fin, "%d", &number) == 1)
			{
				fprintf(fout, "%d ", number);
			}
		}

		for (int i = 0; i < 5; i++)
		{
			if (fscanf(fin, "%d", &number) == 1)
			{
				fprintf(fout, "%d ", number);
			}
		}
	}

	fclose(fout);
	fclose(fin);

}

int main()
{
	int amount;
	srand(time(0));
	printf("how many numbers do you want to add to this file in a format x*10? enter x amount:");
	scanf("%d", &amount);
	filling_in_old(amount);
	filling_in_new(amount);
	return 0;
}



