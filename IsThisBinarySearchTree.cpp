#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool inOrderTrav(Node* node, int& prevData)
{
    if (node == nullptr) return true;
    if (!inOrderTrav(node->left, prevData)) return false;

    if (node->data <= prevData) return false;
    prevData = node->data;

    return(inOrderTrav(node->right, prevData));

}

bool checkBST(Node* root)
{
    int prevData = -1;
    return inOrderTrav(root, prevData);
}

int main()
{
    
}

