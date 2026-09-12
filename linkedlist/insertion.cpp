#include <iostream>

struct Node
{
    int data;
    Node* next;
};

 Node* Creation(Node* first, Node* temp)
{
    int n;
    std::cout<<"Enter the number of Nodes: ";
    std::cin>>n;

    first = new Node;
    first->next=nullptr;

    std::cout<<"Enter the Value of Node 1 : ";
    std::cin>>first->data;

    temp = first;

    for(int i=2; i<=n; i++)
    {
        temp->next = new Node;
        temp=temp->next;

        std::cout<<"Enter the value of Node "<<i<<" : ";
        std::cin>>temp->data;

        temp->next=nullptr;
    }
    return first;
}

int main()
{
    // Original list: 10 -> 20
    Node* first = nullptr;
    Node* temp = nullptr;
    Node* current = first;

    first = Creation(first,temp);

    

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

    current = first;

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