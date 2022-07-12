#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *front1 = 0;
struct Node *rear = 0;

void Enqueue(){
    int key;
    cout<<"Enter the data: ";
    cin>>key;
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = key;
    new_node->next =NULL;
    if(front1 == 0 && rear ==0){
        rear = new_node;
        front1 = new_node;
    }
    else{
        rear->next = new_node;
        rear = new_node;
    }
}

void Dequeue(){
    struct Node *item;
    if(front1 == 0 && rear == 0){
        cout<<"Underflow!"<<endl;
    }
    else if(rear == front1){
        cout<<"Dequeue element is: "<<front1->data<<endl;
        rear = front1 =0;
    }
    else{
        item = front1;
        cout<<"Dequeue element is: "<<front1->data<<endl;
        front1 = front1->next;
        free(item);
    }
}

void peek(){
    if(front1 == 0 && rear == 0){
        cout<<"Underflow!"<<endl;
    }
    else{
        cout<<"Peek element is: "<<front1->data<<endl;
    }
}

void display(){
    struct Node *temp = front1;
    if(front1 == 0 && rear == 0){
        cout<<"Underflow!"<<endl;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


int main(){
    int choice;
    do{
        cout<<"1. Enqueue in queue"<<endl;
        cout<<"2. dequeue in a queue"<<endl;
        cout<<"3. peak in queue"<<endl;
        cout<<"4. Display The queue"<<endl;
        cout<<"0. For Exit"<<endl;
        cout<<"ENTER THE CHOICE : ";
        cin>>choice;
        switch(choice){
        case 0:
            break;
        case 1:
            Enqueue();
            cout<<endl;
            break;

        case 2:
            Dequeue();
            cout<<endl;
            break;

        case 3:
            peek();
            cout<<endl;
            break;

        case 4:
            display();
            cout<<endl;
            break;

        default:
            cout<<"Please enter correct choice"<<endl;
            cout<<endl;
            break;
        }
    }while(choice!=0);

    return 0;
}
