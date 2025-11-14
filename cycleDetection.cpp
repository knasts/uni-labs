#include <iostream>
using namespace std;

struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int nData)
    {
        this->data = nData;
        this->next = nullptr;
    }
};

bool has_cycle(SinglyLinkedListNode* head)
{
    if (head == nullptr) return 0;

    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int getLength(SinglyLinkedListNode* head)
{
    if (head == nullptr) return 0;

    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head;
    int length = 0;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            SinglyLinkedListNode* temp = slow;
            do
            {
                temp = temp->next;
                length++;
            } while (temp != slow);
            return length;
        }
    }
    return 0;
}

int main()
{
    SinglyLinkedListNode* firstHead = new SinglyLinkedListNode(1);
    firstHead->next = new SinglyLinkedListNode(2);
    firstHead->next->next = new SinglyLinkedListNode(3);

    bool firstSycle = has_cycle(firstHead);
    if (firstSycle)
    {
        cout << "first list is cycle :)" << endl;
        cout << "first cycle's length: " << getLength(firstHead) << endl;
    }
    else cout << "first list is not a cycle :(" << endl;

    SinglyLinkedListNode* secondHead = new SinglyLinkedListNode(1);
    SinglyLinkedListNode* node1 = new SinglyLinkedListNode(2);
    SinglyLinkedListNode* node2 = new SinglyLinkedListNode(3);
    SinglyLinkedListNode* node3 = new SinglyLinkedListNode(4);

    secondHead->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;

    bool secondSycle = has_cycle(secondHead);
    if (secondSycle)
    {
        cout << "second list is cycle :)" << endl;
        cout << "second cycle's length: " << getLength(secondHead) << endl;
    }
    else cout << "second list is not a cycle :(" << endl;
}   


