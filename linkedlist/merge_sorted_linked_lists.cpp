#include <iostream>
struct Node
{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

Node* mergedList(Node* head1, Node* head2)
{
    Node* head = nullptr;
    Node* temp = nullptr;
    
    while(head1 != nullptr && head2 != nullptr)
    {
        Node* newNode;

        if(head1->data <= head2->data)
        {
            newNode = new Node(head1->data);
            head1=head1->next;
        }
        else
        {
            newNode = new Node(head2->data);
            head2=head2->next;
        }

        if(head == nullptr)
        {
            head=newNode;
            temp=newNode;
        }
        else
        {
            temp->next=newNode;
            temp=temp->next;
        }
    }

    while(head1 != nullptr)
    {
        temp->next = new Node(head1->data);
        temp=temp->next;
        head1=head1->next;
    }

    while(head2 != nullptr)
    {
        temp->next = new Node(head2->data);
        temp=temp->next;
        head2=head2->next;
    }

    return head;
}

void display(Node* head)
    {
        while(head != nullptr)
        {
            std::cout<<head->data<<" ";
            head=head->next;
        }
    }

int main()
{
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);

    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);

    Node* merged = mergedList(head1, head2);

    std::cout<<"Merged List: ";
    display(merged);
}