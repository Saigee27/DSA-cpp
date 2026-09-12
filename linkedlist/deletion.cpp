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
    Node* first = nullptr;
    Node* temp = nullptr;
    Node* current = first;

    // Enter 5 Nodes (10-50)
    first = Creation(first,temp);

    // Removing beginning value from the Node (10)
    Node* tempp = first;
    first=first->next;
    delete tempp;
    current=first;
    

    // Removing middle value from the Node (30)
    Node* middle = first->next;
    first->next=middle->next;
    delete middle;

    
    // Removing end value from the Node (40)
    while (current->next->next!=nullptr)
    {
        current=current->next;
    }
    tempp=current->next;
    current->next=nullptr;
    delete tempp;


    // Printing the actual result after deletion from beginning, middle and in the end (20)
    current=first;
    while (current != nullptr)
    {
        std::cout<<current->data<<" ";
        current=current->next;
    }
}