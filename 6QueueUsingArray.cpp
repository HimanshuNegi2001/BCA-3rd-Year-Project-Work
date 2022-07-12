#include<bits/stdc++.h>

using namespace std;

#define N 5
int queue1[N];
int rear = -1;
int front = -1;

void enqueue(){
    int data;
    if(rear == N-1){
        cout<<"Overflow!"<<endl;
    }
    else if(rear == -1 && front ==-1){
        cout<<"Enter the data: ";
        cin>>data;
        rear = front = 0;
        queue1[rear] = data;
    }
    else{
        cout<<"Enter the data: ";
        cin>>data;
        rear++;
        queue1[rear] = data;
    }
}

void dequeue(){
    if(rear==-1 && front==-1){
        cout<<"Underflow!"<<endl;
    }
    else if(rear==front){
        rear = front = -1;
    }
    else{
        cout<<"dequeue element is: "<<queue1[front]<<endl;
        front++;
    }
}

void peek(){
    if(rear==-1 && front==-1){
        cout<<"Underflow!"<<endl;
    }
    cout<<"Peek element is: "<<queue1[front]<<endl;
}


void display(){
    int temp = front;
    if(rear==-1 && front==-1){
        cout<<"Underflow!"<<endl;
    }
    else{
        while(temp<=rear){
            cout<<queue1[temp]<<" ";
            temp++;
        }
        cout<<endl;
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
            enqueue();
            cout<<endl;
            break;

        case 2:
            dequeue();
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
