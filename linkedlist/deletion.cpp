#include <iostream>
struct Node
{
    int data;
    Node* next;
};

int main()
{
    Node* first = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;
    first->data=10;
    first->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=fourth;
    fourth->data=40;
    fourth->next=nullptr;
    Node* current = first;

    // Removing beginning value from the Node (10)
    Node* temp = first;
    first=first->next;
    delete temp;
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
    temp=current->next;
    current->next=nullptr;
    delete temp;


    // Printing the actual result after deletion from beginning, middle and in the end (20)
    current=first;
    while (current != nullptr)
    {
        std::cout<<current->data<<" ";
        current=current->next;
    }
}