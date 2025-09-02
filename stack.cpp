#include <iostream>
#include <string>
#include <time.h>
#define N 7 //визначаємо розмір історії -- 7

using namespace std;

//структура даних подія редагування документа
struct Event
{
    string text;
    int row_index;
};

struct Stack
{
    int top_index = -1; //індекс вершини стеку
    int stack_size = 0;
    Event event_arr[N]; //включаємо структуру редагування документа в структуру

    void push(Event event)
    {
        if(top_index + 1 >= N)
        {
            cout << "WARNING: the stack is full -- can`t add a new element: text - '"  << event.text << "' on the " << event.row_index << "th row"<< endl;
        }
        else
        {
            top_index++;
            event_arr[top_index] = event;
            stack_size++;
        }
    }

    void pop()
    {
        if(top_index == -1)
        {
            cout << "WARNING: the stack is empty -- can`t delete anything"  << endl;
        }
        else
        {
            stack_size--;
            top_index--;
        }
    }

    Event top()
    {
        if(top_index == -1)
        {
            Event empty_arr = {"", -1};
            cout << "WARNING: the stack is empty :("  << endl;
            return empty_arr;
        }
        return event_arr[top_index];
    }

    bool emptyy() //перевірка на пустоту
    {
        if(top_index == -1)
        {
            return true;
        }
        return false;
    }

    int sizee()
    {
        return stack_size;
    }

    void clearr()
    {
        top_index = -1;
        stack_size = 0;
    }
};
            //передаємо по копії
void print(Stack my_stack)
{
    if(my_stack.emptyy())
    {
        cout << "Editing history of the document 'My Wishlist' is empty :/" << endl;
    }

    else
    {
        cout << "Editing history of the document 'My Wishlist' contains " << my_stack.sizee() << " events which are:" << endl;
        while(!my_stack.emptyy()) //поки стек не пустий
        {
            Event top_event = my_stack.top();
            cout << "Writing '" << top_event.text << "' on the " << top_event.row_index << "th row" << endl;
            my_stack.pop();
        }
    }
}

Event random_event()
{
    string text;
    int row = (rand() % 100) + 1; //генеруємо випадкове значення для радку від 1 до 100
    if(row % 7 == 0)
    {
        text = "buying a new Maybelline lipstick";
    }
    else if(row % 8 == 0)
    {
        text = "going on a trip with friends to Odesa";
    }
    else if(row % 4 == 0)
    {
        text = "going to Coachella";
    }
    else if(row % 5 == 0)
    {
        text = "going to a BTS concert";
    }
    else if(row % 3 == 0)
    {
        text = "learning a new language";
    }
    else if(row % 6 == 0)
    {
        text = "dyeing hair light pink";
    }
    else
    {
        text = "taking a dance lesson";
    }
    return {text , row};
}
                    //передаємо стек по посиланню, щоб змінити наш стек, а не його копію
void push_events(Stack &my_stack, int k)
{
    for(int i = 0; i < k; i++)
    {
        Event doc_edit = random_event();
        my_stack.push(doc_edit);
    }
}

void pop_events(Stack &my_stack, int k)
{
    for(int i = 0; i < k; i++)
    {
        my_stack.pop();
    }
}

void modified_last_event(Stack &my_stack)
{
    if(my_stack.emptyy())
    {
        cout << "WARNING: the stack is empty -- can`t modify the last event" << endl;
    }
    else
    {
        Event last = my_stack.top();
        pop_events(my_stack, 1);
        string text_add = " in New York";
        last.text += text_add; //змінюємо лише текст
        my_stack.push(last);
    }
}


int main()
{
    srand(time(0));

    Stack Stack_edit_hist;

    cout << "---Adding 4 new events---" << endl;
    push_events(Stack_edit_hist, 4);
    print(Stack_edit_hist);

    cout << "---Adding 5 new events---" << endl;
    push_events(Stack_edit_hist, 5);
    print(Stack_edit_hist);

    cout << "---Deleting 2 last events---" << endl;
    pop_events(Stack_edit_hist, 2);
    print(Stack_edit_hist);

    cout << "---Modifying last event: Adding to the line 'in New York'---" << endl;
    modified_last_event(Stack_edit_hist);
    print(Stack_edit_hist);

    cout << "---Deleting 6 last events---" << endl;
    pop_events(Stack_edit_hist, 6);
    print(Stack_edit_hist);


    return 0;
}
