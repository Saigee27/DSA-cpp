#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

Node* insertStart(Node* first)
{
    Node* temp = new Node;
    cout<<"Enter the value to be inserted in the start: ";
    cin>>temp->data;
    Node* current = first;
    while (current->next != first)
    {
        current = current->next;
    }
    temp->next=first;
    current->next=temp;
    first=temp;
    return first;
}

Node* Creation(Node* first)
{
    int n;
    first = new Node;
    first->next=first;
    cout<<"Enter the elements in the list: ";
    cin>>n;

    cout<<"Enter the value of Node 1: ";
    cin>>first->data;
    Node* temp = first;
    for(int i=2; i<=n; i++)
    {
        temp->next = new Node;
        temp=temp->next;
        cout<<"Enter the value of Node "<<i<<": ";
        cin>>temp->data;
        temp->next=first;
    }
    return first;
}

Node* insertEnd(Node* first)
{
    Node* temp = new Node;
    cout<<"Enter the value to insert in the end: ";
    cin>>temp->data;
    Node* current = first;
    while (current->next != first)
    {
        current = current->next;
    }
    temp->next=first;
    current->next=temp;
    return first;
}


Node* insertMiddle(Node* first)
{
    Node* p = new Node;

    cout << "Enter the value to insert: ";
    cin >> p->data;

    int n;
    cout << "Enter the value you want to insert after: ";
    cin >> n;

    Node* current = first;

    while(current->data != n)
    {
        current = current->next;
    }

    p->next = current->next;
    current->next = p;

    return first;
}

int main()
{
    Node* first = nullptr;
    Node* temp = nullptr;
    Node* current = first;

    first = Creation(first);
    first = insertStart(first);
    first = insertEnd(first);
    first = insertMiddle(first);

    cout<<"\n";

    current = first;
    do {
        cout<<current->data<<" ";
        current=current->next;
    }while(current != first);
    return 0;
}
