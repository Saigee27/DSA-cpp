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

    first = Creation(first,temp);
    

    int target = 0;
    std::cout<<"Enter the number to be found: ";
    std::cin>>target;

    bool found = false;
    int position = 1;

    current = first;
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