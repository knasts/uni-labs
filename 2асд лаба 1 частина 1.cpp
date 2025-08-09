#include <iostream>
#include <ctime>
#include <string>
//динамічний масив:

using namespace std;

struct Scholarship
{
    int sch_amount;
    string card_number;
    bool sch_availab;
};

void relocateMemory(Scholarship*& array, int& capacity, int current_size)
{
    int new_capacity = capacity * 2;
    Scholarship* new_array = new Scholarship[new_capacity];
    for(int i = 0; i < current_size; i++)
    {
        new_array[i] = array[i];
    }
    delete[] array;
    array = new_array;
    capacity = new_capacity;
}

struct DynamicArray
{
    int capacity, current_size, index;
    Scholarship empty_arr = {0, "", false};
    Scholarship* list;


    DynamicArray(int first_capacity = 20)
    {
        capacity = first_capacity;
        current_size = 0;
        list = new Scholarship[capacity];
    }

    ~DynamicArray()
    {
        delete[] list;
    }


    void push_back(Scholarship new_stud)
    {
        if(current_size >= capacity)
        {
            relocateMemory(list, capacity, current_size);
        }

        list[current_size] = new_stud;
        current_size++;
    }
    void push_front(Scholarship new_stud)
    {
        if(current_size >= capacity)
        {
            relocateMemory(list, capacity, current_size);
        }
        for(int i = current_size; i > 0; i++) //здвигаємо праворуч
        {
            list[i] = list[i-1];
        }
        list[0] = new_stud;
        current_size++;
    }
    Scholarship pop_back()
    {
        if(current_size == 0)
        {
            cout << "WARNING: the array is empty :("  << endl;
            return empty_arr;
        }
        Scholarship last_elem = list[current_size - 1];
        current_size--;
        return last_elem;

    }
    Scholarship pop_front()
    {
        if(current_size == 0)
        {
            cout << "WARNING: the array is empty :("  << endl;
            return empty_arr;
        }
        Scholarship first_el = list[0];
        for(int i = 0; i < current_size - 1; i++)
        {
            list[i] = list[i+1];
        }
        current_size--;
        return first_el;
    }
    Scholarship get(int index)
    {
        if(index < 0 || index >= current_size)
        {
            cout << "index is reaching out of the array" << endl;
            return empty_arr;
        }
        return list[index];
    }
    int size()
    {
        return current_size;
    }
    void clear()
    {
        delete[] list;
        current_size = 0;
        capacity = 20;
        list = new Scholarship[capacity];
    }
    void print()
    {
        for(int i = 0; i < current_size; i++)
        {
            cout << "Student`s scholarship under " << i+1 << " number in the array has next atributes:" << endl;
            cout << "avaliable: " << (list[i].sch_availab ? "yes:)" : "no:(") << ", amount: " << list[i].sch_amount << ", card number: " << list[i].card_number << endl;
        }
    }
    void insert(Scholarship stud,int n)
    {
        if(n > current_size || n < 0)
        {
            cout << "can't insert new element: invalid index" << endl;
            return;
        }
        if(current_size >= capacity)
        {
            relocateMemory(list, capacity, current_size);
        }

        for(int i = current_size; i > n; i--)
        {
            list[i] = list[i-1];
        }
        list[n] = stud;
        current_size++;
    }
    void remove(int n)
    {
        if(n >= current_size || n < 0)
        {
            cout << "can't delete " << n << " element: invalid index" << endl;
            return;
        }

        for(int i = n; i < current_size; i++)
        {
            list[i] = list[i+1];
        }
        current_size--;
    }

};

Scholarship rand_sch_stud()
{
    string card_number = to_string((rand() % 15) + 1);
    int sch_amount;
    bool sch_availab = true;
    int rand_num = (rand() % 1000) + 1;

    if(rand_num % 25 == 0) sch_amount = 2800;
    else if(rand_num % 5 == 0) sch_amount = 2000;
    else if(rand_num % 2 == 0) sch_amount = 1000;
    else
    {
        sch_amount = 0;
        sch_availab = false;
    }

    while(card_number.size() < 16)
    {
        card_number += to_string(rand() % 10);
    }

    return {sch_amount, card_number, sch_availab};

}

void push_elem(DynamicArray &array)
{
    Scholarship new_stud = rand_sch_stud();
    array.push_back(new_stud);
}

int main()
{
    DynamicArray stud_scholarship;

    double seconds = 0;
    double seconds_all = 0;
    int number;
    srand(time(0));

    for(int i = 0; i < 50000; i++)
    {
        clock_t startTime = clock();
        push_elem(stud_scholarship);
        clock_t endTime = clock();
        seconds += double (endTime - startTime) / CLOCKS_PER_SEC;
    }

    cout << "the execution time of pushing 50000 elements at the end of the array: " << seconds << endl;
    seconds_all += seconds;
    seconds = 0;

    for(int i = 0; i < 10000; i++)
    {
        clock_t startTime = clock();
        push_elem(stud_scholarship);
        clock_t endTime = clock();
        seconds += double (endTime - startTime) / CLOCKS_PER_SEC;
    }
    seconds_all += seconds;
    cout << "the execution time of pushing 10000 elements at the beginning of the array: " << seconds << endl;
    seconds = 0;

    for(int i = 0; i < 20000; i++)
    {
        clock_t startTime = clock();
        number = rand() % 60000;
        stud_scholarship.get(number);
        clock_t endTime = clock();
        seconds += double (endTime - startTime) / CLOCKS_PER_SEC;
    }
    seconds_all += seconds;
    cout << "the execution time of getting 20000 random elements of the array: " << seconds << endl;
    seconds = 0;

    for(int i = 0; i < 5000; i++)
    {
        clock_t startTime = clock();
        stud_scholarship.pop_front();
        clock_t endTime = clock();
        seconds += double (endTime - startTime) / CLOCKS_PER_SEC;
    }
    seconds_all += seconds;
    cout << "the execution time of popping 5000 first elements of the array: " << seconds << endl;
    seconds = 0;

    for(int i = 0; i < 5000; i++)
    {
        clock_t startTime = clock();
        stud_scholarship.pop_back();
        clock_t endTime = clock();
        seconds += double (endTime - startTime) / CLOCKS_PER_SEC;
    }
    seconds_all += seconds;
    cout << "the execution time of popping 5000 last elements of the array: " << seconds << endl;
    cout << "~~total execution time: " << seconds_all << endl;
    seconds = 0;
    seconds_all = 0;

    int current_size = stud_scholarship.size();
    for(int i = 0; i < 10000; i++)
    {
        clock_t startTime = clock();
        number = rand() % current_size;
        Scholarship new_stud = rand_sch_stud();
        stud_scholarship.insert(new_stud, number);
        clock_t endTime = clock();
        seconds += double (endTime - startTime) / CLOCKS_PER_SEC;
    }
    seconds_all += seconds;
    cout << "the execution time of inserting 10000 random elements of the array: " << seconds_all << endl;
    seconds = 0;

    current_size = stud_scholarship.size();
    for(int i = 0; i < 10000; i++)
    {
        clock_t startTime = clock();
        number = rand() % current_size;
        stud_scholarship.remove(number);
        clock_t endTime = clock();
        seconds += double (endTime - startTime) / CLOCKS_PER_SEC;
    }
    seconds_all += seconds;
    cout << "the execution time of removing 10000 random elements of the array: " << seconds << endl;
    cout << "~~total execution time: " << seconds_all << endl;


    return 0;
}
