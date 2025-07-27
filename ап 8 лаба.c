/*14. Заданий масив структур, який містить прізвища і назви груп.
Масив впорядкувати за прізвищами. Програма повинна видаляти запис, який
містить задане прізвище, зсуваючи елементи вперед (заповнюючи ними
порожнє місце).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Students
{
    char surname[20];
    int group;
} student;


void bubble_sort(struct Students* array, int N)
{
    struct Students temp;
    for(int i = 0; i < N; i++)
    {                       //-1 щоб не вийти за межі масиву
        for(int j = 0; j < N - i - 1; j++)
        {
            if(strcmp(array[j].surname, array[j + 1].surname) > 0) //якщо strcmp повертає додатне значення, то перший рядок йде за алфавітом раніше
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void print_list(struct Students* array, int N)
{
    for(int i = 0; i < N; i++)
    {
        printf("Surname of the %d student is %s, group %d \n", i + 1 , array[i].surname, array[i].group);
    }
}
                  //подвійний вказівник, бо ми знімнюємо не лише вміст, а й сам вказівник
int checking(struct Students** array, int* N, struct Students stud)
{
    int index = -1;
    int i;
    for(i = 0; i < *N; i++)
    {
        if(strcmp((*array)[i].surname, stud.surname) == 0) //якщо strcmp повертає 0, то перший рядок = другому
        {
            index = i;
            break;
        }
    }

    if(index == -1) //якщо елемент не знайдемо, то повертаємо -1
    {
        return -1;
    }

    for(i = index; i < *N - 1; i++)
    {
       (*array)[i] = (*array)[i + 1]; //зміщуємо всі елементи нижче знайденого на 1 вгору
    }

    (*N)--;
    struct Students* temp_arr = realloc(*array, (*N) * sizeof(struct Students)); //перевиділяємо пам'ять
    if (temp_arr == NULL && *N > 0)
    {
        return -2;
    }

    *array = temp_arr; //якщо пам'ять перевиділилася, то змінюємо наш масив
    return 0;
}

int main()
{
    int N = 5;
    int i, answ;

    struct Students* arrayy = (struct Students*)malloc(N * sizeof(struct Students));
    printf("If you want to work with default list press 1, if you want to create your own one enter any number: ");
    scanf("%d", &answ);
    if(answ == 1)
    {
        strcpy(arrayy[0].surname, "Kim");
        strcpy(arrayy[1].surname, "Min");
        strcpy(arrayy[2].surname, "Jung");
        strcpy(arrayy[3].surname, "Jeon");
        strcpy(arrayy[4].surname, "Park");
    }
    else
    {
        for(i = 0; i < N; i++)
        {
            printf("Enter surname of the %d student:  ", i + 1);
            scanf("%19s", arrayy[i].surname); //введення прізвища
        }
    }

    srand(time(0));
    for(i = 0; i < N; i++)
    {
        arrayy[i].group = (rand() % 20) + 1; //випадково генеруємо номер групи
    }

    bubble_sort(arrayy, N); // відсортовуємо "бульбашкою" масив за алфавітом
    printf("Our list of the students:\n");
    print_list(arrayy, N);

    printf("Enter surname of the student that you are looking for:  ");
    scanf("%19s", student.surname);
                            //передаємо адреси змінних у функцію
    int result = checking(&arrayy, &N, student);
    if(result == -1)
    {
        printf("Student with this surname is not on this list");
    }
    else if(result == -2)
    {
        printf("Memory reallocation during modifying the array failed\n");
    }
    else
    {
        bubble_sort(arrayy, N);
        printf("Our list of the students: (without %s)\n", student.surname);
        print_list(arrayy, N);
    }

    free(arrayy);
    return 0;
}
