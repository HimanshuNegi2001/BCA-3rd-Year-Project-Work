#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *top=0;

void push(){
    int key;
    cout<<"Enter the data: ";
    cin>>key;
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = key;
    new_node->next = top;
    top = new_node;
}

void pop(){
    struct Node *temp = top;
    if(top == 0){
        cout<<"Underflow!"<<endl;
    }
    else{
        cout<<"pop element is: "<<top->data;
        top = top->next;
        free(temp);
    }
    cout<<endl;
}

void peek(){
    if(top == 0){
        cout<<"Underflow!"<<endl;
    }
    else{
        cout<<"Peek element is : "<<top->data<<endl;
    }
}
void display(){
    struct Node *temp = top;
    if(top == 0){
        cout<<"Underflow!"<<endl;
    }
    else{
        while(temp!=0){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

int main(){
    int choice;
    do{
        cout<<"1. Push in stack"<<endl;
        cout<<"2. Pop in a stack"<<endl;
        cout<<"3. peak in stack"<<endl;
        cout<<"4. Display The stack"<<endl;
        cout<<"0. For Exit"<<endl;
        cout<<"ENTER THE CHOICE : ";
        cin>>choice;
        switch(choice){
        case 0:
            break;
        case 1:
            push();
            cout<<endl;
            break;

        case 2:
            pop();
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
