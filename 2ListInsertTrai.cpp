
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node * insertElement(struct Node *head){
    struct Node *newNode,*ptr;
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if(head==NULL){
        newNode->next=NULL;
        head = newNode;
        cout<<"Linked List Created"<<endl;
    }
    else{
        ptr = head;
        while(ptr->next!=NULL){
            ptr= ptr->next;
        }
        ptr->next = newNode;
        newNode->next = NULL;
    }
    return head;
};

void display(struct Node *head){
    struct Node *p=head;
    if(p==NULL){
        cout<<"List is empty"<<endl;
    }
    else{
         cout<<"Element are : ";
        while(p!=NULL){
            cout<<p->data<<" ";
            p = p->next;
        }
    }
    cout<<endl;
}

int main(){
    struct Node *head = NULL;
    int choice;
    do{
        cout<<"1. Insert New Element"<<endl;
        cout<<"2. Display The List"<<endl;
        cout<<"0. For Exit"<<endl;
        cout<<"ENTER THE CHOICE : ";
        cin>>choice;
        switch(choice){
        case 0:
            break;
        case 1:
            head = insertElement(head);
            cout<<endl;
            break;

        case 2:
            display(head);
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
