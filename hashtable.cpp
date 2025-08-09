#include <iostream>
#include <string>
#include "C:\\Users\\ASUS\\OneDrive\\Desktop\\АСД\\2асд лаба 2\\лабка асд\\linkedlist.h"
#include "C:\\Users\\ASUS\\OneDrive\\Desktop\\АСД\\2асд лаба 2\\лабка асд\\hashtable.h"
using namespace std;

Hash_table::Hash_table()
{
    buckets_size = 10000;
    buckets_arrays = new Linked_list[buckets_size];
    total_amount = 0;
}

Hash_table::~Hash_table()
{
    delete[] buckets_arrays;
}

long long Hash_table::hash(long long key)
{
    return key % buckets_size; //метод Division
    //long long number = 0; // метод Mid-Square
    //int len;
    //long long sqr_k = key * key;

    //string sqr_key = to_string(sqr_k);
    //len = sqr_key.length();
    //number = static_cast <int> (len / 2);

    //if (len < 3)
    //{
    //    return (sqr_key[number] - '0') % buckets_size;
    //}
    //string hash_str = sqr_key.substr(number - 1, 3);
    //return stoi(hash_str) % buckets_size; // string в int
}

void Hash_table::relocateMemory()
{
    int new_buckets_size = buckets_size * 2;
    Linked_list* new_array = new Linked_list[new_buckets_size];
    for (int i = 0; i < buckets_size; i++)
    {
        Hash_node* node = buckets_arrays[i].head;
        while (node)
        {
             Hash_node* temp = node->next_element;
             int index = node->key % new_buckets_size;
             Linked_list* list = &new_array[index];
             list->push_front(node->key, node->value);
             node = temp; 
        }
        
    }
    delete[] buckets_arrays;
    buckets_size = new_buckets_size;
    buckets_arrays = new_array;
}

float Hash_table::load_factor()
{
    return (float)total_amount / buckets_size;
}

Data* Hash_table::find(long long key)
{
    int index = hash(key);
    Linked_list* list = &buckets_arrays[index];
    return list->find(key);
}
void Hash_table::insert(long long key, Data value)
{
    if (load_factor() >= max_load)
    {
        relocateMemory();
    }
    int index = hash(key);
    Linked_list* list = &buckets_arrays[index];
    Data* found = list->find(key);
    if (!found)
    {
        list->push_front(key, value);
        total_amount++;
    }
    else
    {
        *found = value;
    }
}

void Hash_table::erase(long long key)
{
    int index = hash(key);
    Hash_node* elem = buckets_arrays[index].head;
    while (elem != nullptr)
    {
        if (elem->key == key)
        {
            buckets_arrays[index].remove(key);
            total_amount--;
            return;
        }
        elem = elem->next_element;
    }
}
int Hash_table::size()
{
    return total_amount;
}