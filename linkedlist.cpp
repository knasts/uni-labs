#include <iostream>
#include <string>
#include "C:\\Users\\ASUS\\OneDrive\\Desktop\\АСД\\2асд лаба 2\\лабка асд\\linkedlist.h"
using namespace std;

Data::Data()
{
    int num = (rand() % 120) + 25;
    unpassed_sbj = num % 17;
    deadline_days = static_cast<float>(num) / 20.0f;
    expulsion_risk = ((num % 2) ? true : false);
    
}

Linked_list::Linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }

Linked_list::~Linked_list()
    {
        clear();
    }


void Linked_list::push_front(long long keyy, Data new_stud)
    {
        Hash_node* new_node = new Hash_node(keyy, new_stud);
        new_node->next_element = head;

        head = new_node;
        if (tail == nullptr)
        {
            tail = new_node;
        }
    }
void Linked_list::push_back(long long key, Data new_stud)
    {
        Hash_node* new_node = new Hash_node(key, new_stud);
        new_node->next_element = nullptr;

        if (!head)
        {
            head = tail = new_node;
            return;
        }
        tail->next_element = new_node;
        tail = new_node;
    }
Data Linked_list::get(int n)
    {
        int i = 0;
        Hash_node* current = head;
        while (i < n && current != nullptr)
        {
            current = current->next_element;
            i++;
        }
        if (current == nullptr)
        {
            cout << "index " << n << " is out of range" << endl;
            return {};
        }
        return current->value; //звертаємось до поля value, щоб отримати об'єкт типу scholarship
    }
void Linked_list::pop_front()
    {
        if (!head)
        {
            return;
        }
        Hash_node* to_delete = head;
        head = head->next_element;
        if (!head)
        {
            tail = nullptr;
        }
        delete to_delete;
    }

void Linked_list::pop_back()
    {
        if (!head)
        {
            return;
        }

        if (tail == head)
        {
            delete head;
            head = tail = nullptr;
            return;
        }

        Hash_node* prev = head;
        while (prev->next_element != tail)
        {
            prev = prev->next_element;
        }

        delete tail;
        tail = prev;
        tail->next_element = nullptr;
    }
int Linked_list::size()
    {
        Hash_node* element = head;
        int n = 0;
        while (element != nullptr)
        {
            n++;
            element = element->next_element;
        }
        return n;
    }
void Linked_list::print()
    {
        Hash_node* element = head;
        while (element != nullptr)
        {
            cout << "Amount of unpassed subjects : " << element->value.unpassed_sbj << ", ";
            cout << "Days until deadline : " << element->value.deadline_days << ", ";
            cout << "Expulsion risk : " << (element->value.expulsion_risk ? "Yes" : "No") << endl;
            element = element->next_element;
        }
    }
void Linked_list::clear()
    {
        Hash_node* element = head;
        while (element != nullptr)
        {
            Hash_node* temp_elem = element;
            element = element->next_element;
            delete temp_elem;
        }
        head = nullptr;
        tail = nullptr;
    }

void Linked_list::insert(int n, long long keyy, Data new_stud)
{
    if (n < 0 || n > size())
    {
        cout << "can't insert element: index " << n << " is out of range" << endl;
        return;
    }

    if (n == 0) 
    {
        push_front(keyy, new_stud);
        return;
    }

    Hash_node* new_node = new Hash_node(keyy, new_stud);
    Hash_node* element = head;
    for (int k = 0; k < n - 1; k++) // знаходимо шукану позицію
    {
        element = element->next_element;
    }

    new_node->next_element = element->next_element; // element стоїть перед нашим індексом
    element->next_element = new_node;

    if (new_node->next_element == nullptr) // якщо вставка в кінець, то оновлюємо хвіст
    {
        tail = new_node;
    }
}

void Linked_list::remove(long long key)
    {  
       if (!head)  
       {  
           cout << "can't delete element: list is empty" << endl;  
           return;  
       }  

       if (head->key == key)  
       {  
           pop_front();  
           return;  
       }  

       Hash_node* element = head;
       while (element->next_element != nullptr && element->next_element->key != key)  
       {  
           element = element->next_element;  
       }  

       if (element->next_element == nullptr)  
       {  
           cout << "can't delete element: key " << key << " not found" << endl;  
           return;  
       }  

       Hash_node* to_delete = element->next_element;
       element->next_element = to_delete->next_element;  
       if (to_delete->next_element == nullptr)  
       {  
           tail = element;  
       }  
       delete to_delete;  
    }  

Data* Linked_list::find(long long key)
    {
       Hash_node* current = head;
       while (current != nullptr) 
       {
           if (current->key == key) 
           { 
               return &current->value;
           }
           current = current->next_element;
       }
       return nullptr;
    }
