#include<bits/stdc++.h>

#define N 5
int stack1[N];
int top = -1;

using namespace std;

int push(){
    int data;
    if(top==N-1){
        cout<<"Overflow!"<<endl;
    }
    else{
        cout<<"Enter the data: ";
        cin>>data;
        top++;
        stack1[top] = data;
    }
    return 0;
}

int pop(){
    int item;
    if(top == -1){
        cout<<"Underflow!"<<endl;
    }
    else{
        item = stack1[top];
        top--;
        cout<<"Pop element is: "<<item<<endl;
    }
    return 0;
}

int peek(){
    if(top == -1){
        cout<<"Underflow!"<<endl;
    }
    else{
        cout<<stack1[top]<<endl;
    }
    return 0;
}

int display(){
    if(top == -1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        for(int i=0;i<=top;i++){
            cout<<stack1[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
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


