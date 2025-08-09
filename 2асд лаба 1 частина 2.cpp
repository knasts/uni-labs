#include <iostream>
#include <time.h>
#include <string>
using namespace std;

struct Scholarship
{
    int sch_amount;
    string card_number;
    bool sch_availab;
};

struct Node
{
    Scholarship value;
    Node* next_element;
};

struct Linked_list
{
    Node* head;
    Node* tail;

    Linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }

    ~Linked_list()
    {
        clear();
    }


    void push_front(Scholarship new_stud)
    {
        Node* new_node = new Node();
        new_node->value = new_stud;
        new_node->next_element = head;

        head = new_node;
        if(tail == nullptr)
        {
            tail = new_node;
        }
    }
    void push_back(Scholarship new_stud)
    {
        Node* new_node = new Node();
        new_node->value = new_stud;
        new_node->next_element = nullptr;

        if(!head)
        {
            head = tail = new_node;
            return;
        }
        tail->next_element = new_node;
        tail = new_node;
    }
    Scholarship get(int n)
    {
        int i = 0;
        Node* current = head;
        while(i < n && current != nullptr)
        {
            current = current->next_element;
            i++;
        }
        if(current == nullptr)
        {
            cout << "index " << n << " is out of range" << endl;
            return {};
        }
        return current->value; //звертаємось до поля value, щоб отримати об'єкт типу scholarship
    }
    void pop_front()
    {
        if(!head)
        {
            return;
        }
        Node* to_delete = head;
        head = head->next_element;
        if(!head)
        {
            tail = nullptr;
        }
        delete to_delete;
    }

    void pop_back()
    {
        if(!head)
        {
            return;
        }

        if(tail == head)
        {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* prev = head;
        while(prev->next_element != tail)
        {
            prev = prev->next_element;
        }

        delete tail;
        tail = prev;
        tail->next_element = nullptr;
    }
    int size()
    {
        Node* element = head;
        int n = 0;
        while(element != nullptr)
        {
            n++;
            element = element->next_element;
        }
        return n;
    }
    void print()
    {
        Node* element = head;
        while(element != nullptr)
        {
            cout << "Scholarship Amount: " << element->value.sch_amount << ", ";
            cout << "Card Number: " << element->value.card_number << ", ";
            cout << "Available: " << (element->value.sch_availab ? "Yes" : "No") << endl;
            element = element->next_element;
        }
    }
    void clear()
    {
        Node* element = head;
        while(element != nullptr)
        {
            Node* temp_elem = element;
            element = element->next_element;
            delete temp_elem;
        }
        head = nullptr;
        tail = nullptr;
    }
    void insert(int n, Scholarship new_stud)
    {
        Node* new_node = new Node();
        new_node->value = new_stud;
        new_node->next_element = nullptr;

        if(n == 0)//якщо вставка в початок
        {
            push_front(new_stud);
            return;
        }

        Node* element = head;
        for(int k = 0; k < n-1; k++)//знаходимо шукану позицію
        {
            if(element == nullptr)
            {
                cout << "can't insert element: index " << n << " is out of range" << endl;
                delete new_node;
                return;
            }
            element = element->next_element;
        }

        new_node->next_element = element->next_element; //element стоїть перед нашим індексом
        element->next_element = new_node;

        if(new_node->next_element == nullptr)//якщо вставка в кінець, то оновлюємо хвіст
        {
            tail = new_node;
        }
    }

    void remove(int n)
    {
        Node* current;
        if(n == 0)
        {
            pop_front();
            return;
        }
        Node* element = head;
        for(int k = 0; k < n-1; k++)//знаходимо шукану позицію
        {
            if(element == nullptr || element->next_element == nullptr)
            {
                cout << "can't delete element: index " << n << " is out of range" << endl;
                return;
            }
            element = element->next_element;
        }

        current = element->next_element;
        if(current == nullptr)
        {
            cout << "can't delete element: index " << n << " is out of range" << endl;
            return;
        }

        element->next_element = current->next_element;
        if(current->next_element == nullptr)
        {
            tail = element;
        }
        delete current;
    }
};

Scholarship rand_sch_stud()
{
    string card_number = to_string((rand() % 15) + 1);
    int sch_amount;
    bool sch_availab = true;
    int rand_num = (rand() % 100) + 1;

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
        card_number += card_number.back();
    }

    return {sch_amount, card_number, sch_availab};
}


void push_elem(Linked_list &list)
{
    Scholarship new_stud = rand_sch_stud();
    list.push_back(new_stud);
}


int main()
{
    Linked_list stud_scholarship;

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

    cout << "the execution time of pushing 50000 elements at the end of the list: " << seconds << endl;
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
    cout << "the execution time of pushing 10000 elements at the beginning of the list: " << seconds << endl;
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
    cout << "the execution time of getting 20000 random elements of the list: " << seconds << endl;
    seconds = 0;

    for(int i = 0; i < 5000; i++)
    {
        clock_t startTime = clock();
        stud_scholarship.pop_front();
        clock_t endTime = clock();
        seconds += double (endTime - startTime) / CLOCKS_PER_SEC;
    }
    seconds_all += seconds;
    cout << "the execution time of popping 5000 first elements of the list: " << seconds << endl;
    seconds = 0;

    for(int i = 0; i < 5000; i++)
    {
        clock_t startTime = clock();
        stud_scholarship.pop_back();
        clock_t endTime = clock();
        seconds += double (endTime - startTime) / CLOCKS_PER_SEC;
    }
    seconds_all += seconds;
    cout << "the execution time of popping 5000 last elements of the list: " << seconds << endl;
    cout << "~~total execution time: " << seconds_all << endl;
    seconds = 0;
    seconds_all = 0;

    int current_size = stud_scholarship.size();
    for(int i = 0; i < 10000; i++)
    {
        clock_t startTime = clock();
        number = rand() % current_size;
        Scholarship new_stud = rand_sch_stud();
        stud_scholarship.insert( number, new_stud);
        clock_t endTime = clock();
        seconds += double (endTime - startTime) / CLOCKS_PER_SEC;
    }
    seconds_all += seconds;
    cout << "the execution time of inserting 10000 random elements of the list: " << seconds_all << endl;
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
    cout << "the execution time of removing 10000 random elements of the list: " << seconds << endl;
    cout << "~~total execution time: " << seconds_all << endl;
    return 0;
}
