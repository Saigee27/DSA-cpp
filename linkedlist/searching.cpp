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

    int target = 30;

    bool found = false;
    int position = 1;

    while(current!=nullptr)
    {
        if(current->data==target)
        {
            std::cout<<"Target "<<current->data<<" Found at "<<position;
            found = true;
            break;
        }
        current=current->next;
        position++;
    }
    if(!found)
    {
        std::cout<<"Target never found";
    }
}