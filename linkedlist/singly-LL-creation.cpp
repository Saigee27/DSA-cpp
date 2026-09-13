#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* Creation(Node* first, Node* temp)
{
    int n;
    cout<<"Enter the number of Node: ";
    cin>>n;

    first = new Node;
    cout<<"Enter the value of Node 1: ";
    cin>>first->data;

    first->next=nullptr;

    temp = first;

    for (int i=2; i<=n; i++)
    {
        temp->next = new Node;
        temp=temp->next;

        cout<<"Enter the value of Node "<<i<<": ";
        cin>>temp->data;

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

    cout<<"\n";
    
    current = first;
    while (current != nullptr)
    {
        cout<<current->data<<" ";
        current=current->next;
    }
    return 0;
}