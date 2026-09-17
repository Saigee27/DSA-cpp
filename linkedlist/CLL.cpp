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


Node* deletionStart(Node* first)
{
    Node* current = first;

    while(current->next != first)
    {
        current = current->next;
    }

    first = first->next;
    delete current->next;
    current->next = first;

    return first;
}

Node* deletionEnd(Node* first)
{
    Node* current = first;

    while(current->next->next != first)
    {
        current = current->next;
    }

    delete current->next;
    current->next = first;

    return first;
}

Node* deletionMiddle(Node* first)
{
    Node* current = first;

    int n;
    cout << "Enter the value to be deleted: ";
    cin >> n;

    while(current->next->data != n)
    {
        current = current->next;
    }

    Node* p = current->next;
    current->next = p->next;
    delete p;

    return first;
}


Node* searching(Node* first)
{
    int target = 0;
    cout<<"Enter the value to search in linked list: ";
    cin>>target;

    bool found = false;
    int position = 1;

    Node* current = first;
    
    do
    {
        if(current->data == target)
        {
            cout << "The target value " << target
                 << " is found at " << position;

            found = true;
            break;
        }

        current = current->next;
        position++;

    } while(current != first);

    if(!found)
    {
        cout << "Target is not found";
    }

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
    first = searching(first);

    cout<<"\n";

    current = first;
    do {
        cout<<current->data<<" ";
        current=current->next;
    }while(current != first);
    

    cout<<"\n";

    first = deletionStart(first);
    first = deletionEnd(first);
    first = deletionMiddle(first);

    current = first;
    do {
        cout<<current->data<<" ";
        current=current->next;
    }while(current != first);
    return 0;
}
