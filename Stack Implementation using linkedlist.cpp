#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

node *push(node *head)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    if (!newnode)
        return head;
    
    cout<<"Enter the element to be pushed: ";
    cin>>newnode->data;
    newnode->next=NULL;

    if (head==NULL)
        head=newnode;

    else
    {
        newnode->next=head;
        head=newnode;
    }

    return head;
}

node *pop(node *head)
{
    if (head==NULL)
    {
        cout<<"Stack is empty";
        return head;
    }

    node *temp=head;
    head=head->next;
    free(temp);
    cout<<"Element deleted";
    return head;
}

void topStack(node *head)
{
    if (head==NULL)
    {
        cout<<"Stack is empty";
        return;
    }
    
    cout<<"Element at the top of the stack: ";
    cout<<head->data;
}

int main()
{
    node *head=NULL;    
    while (1)
    {
        cout << "\n\n1-Push an element";
        cout << "\n2-Pop an element";
        cout << "\n3-Top of the stack";
        cout << "\n4-Exit";
        cout << "\nChoose the option: ";
        int num;
        cin >> num;
        cout << "\n";
        if (num == 1)
            head=push(head);
        else if (num == 2)
            head=pop(head);
        else if (num == 3)
            topStack(head);
        else if (num == 4)
            break;
        else
            cout << "Invalid entry";
    }
    return 0;
}
