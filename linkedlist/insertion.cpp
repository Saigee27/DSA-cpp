#include <iostream>

struct Node
{
    int data;
    Node* next;
};

int main()
{
    // Original list: 10 -> 20
    Node* first = new Node;
    Node* second = new Node;

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = nullptr;


    // 1. Insertion at beginning
    Node* beginningNode = new Node;
    beginningNode->data = 5;

    beginningNode->next = first;
    first = beginningNode;


    // 2. Insertion in middle
    Node* middleNode = new Node;
    middleNode->data = 15;

    middleNode->next = first->next;
    first->next = middleNode;


    // 3. Insertion at tail
    Node* tailNode = new Node;
    tailNode->data = 30;

    Node* current = first;

    while(current->next != nullptr)
    {
        current = current->next;
    }

    current->next = tailNode;
    tailNode->next = nullptr;


    // Print the final list
    current = first;

    while(current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    return 0;
}