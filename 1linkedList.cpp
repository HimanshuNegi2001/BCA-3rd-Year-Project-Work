#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};
int flag;

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
    flag++;
    return head;
};

struct Node * deleteElement(struct Node * head,int position){
    struct Node *p = head;
    struct Node *temp;

    if(p==NULL){
        cout<<"List is empty!"<<endl;
    }
    else if(position==1){
        head = p->next;
        flag--;
    }
    else if(position>flag){
        cout<<"Not enough element in list"<<endl;
    }
    else{
        for(int i=1;i<position;i++){
            if(p!=NULL){
                temp = p;
                p = p->next;
            }
        }
        temp->next= temp->next->next;
        free(p);
        flag--;
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
        cout<<"3. Delete The element"<<endl;
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

        case 3:
            int num;

            cout<<"Enter the position where you delete the element"<<endl;
            cin>>num;
            head = deleteElement(head,num);
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
