#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next ;
};
class Queue
{
    Node *front, *rear;

public:
    Queue()
    {
        front = rear = NULL; 

    }
    void Enqueue(int elem)  
    {
        Node *newnode;
        newnode = new Node;
        newnode->data = elem;
        newnode->next = NULL;

        if(front == NULL)
            front = rear = newnode;
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }
    void Dequeue()      
    {
        Node *temp;
        if(front == NULL)
            cout<<"Queue is Empty";
        else
        {
            temp= front;
            front = front->next;
            delete temp;
        }

    }
    void display()
    {
        Node *temp;
        temp= front;
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    Queue Q1;
    Q1.Enqueue(10);
    cout<<"Queue after First Enqueue :";
    Q1.display();
    cout<<"\n";
    Q1.Enqueue(20);
    cout<<"Queue after Second Enqueue :";
    Q1.display();
    cout<<"\n";
    Q1.Dequeue();
    cout<<"Queue after Dequeue :";
    Q1.display();
}
