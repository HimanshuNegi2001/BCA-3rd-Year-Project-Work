#include<iostream>
#include<cstdlib>
using namespace std;

int data,item,pos;

class Node{
	public:
		int data;
		Node* link;
};

Node *insertAtBeg(Node* n,int new_data){
	Node *temp=NULL;
	temp=new Node();
	cout<<"temp is:"<<temp;
	temp->data=new_data;
	temp->link=n;
	n=temp;
	return n;
}

Node *insertAtEnd(Node *head, int data){
	Node *n=head;
	while(n->link!=NULL){
		n=n->link;
	}
	Node *temp=new Node();
	temp->data=data;
	temp->link=NULL;
	n->link=temp;
	return head;
}


Node *create(Node *head){
	int i,n;
	cout<<"Enter the number of nodes:";
	cin>>n;
	head=NULL;
	if(n==0)
		return head;
	cout<<"Enter the element to be inserted:";
	cin>>data;
	head=insertAtBeg(head,data);
	for(i=2;i<=n;i++){
		cout<<"Enter the element to be inserted:";
		cin>>data;
		head=insertAtEnd(head,data);
	}
	return head;
}


Node *insertAtAfterNode(Node *head,int data, int item){
	Node *n=head;

 	Node *temp=new Node();
	temp->data=data;
	while(n->link!=NULL){
		if(n->data==item){
			temp->link=n->link;
			n->link=temp;
			return head;
		}
		n=n->link;
	}
	cout<<"Entered item not found";
}

/*Node *insertAtBeforeNode(Node *head,int data,int item){
	Node *n=head;
	Node *prev=NULL;
	Node *temp=new Node();
	temp->data=data;
	while(n->link!=NULL){
		if(n->data==item){
		temp->link=n;
		prev->link=temp;
		return head;	
		}
	prev=n;
	n=n->link;
	
	}
} */

Node *insertAtBeforeNode(Node *head,int data,int item){
	Node *n=head;
	Node *temp=new Node();
	temp->data=data;
	while(n->link!=NULL){
		if(n->link->data==item){
			temp->link=n->link;
			n->link=temp;
			return head;
		}
		n=n->link;
	}
	cout<<" "<<item<<" is not present in the list.";
}

Node *insertAtPosition(Node *head, int data, int pos){
	Node *n;
	Node *temp=new Node();
	temp->data=data;
	if(pos==1){
		temp->link=head;
		head = temp;
		return head;
	}
	n=head;
	int i;
	for(i=1;i<pos-1 && n!=NULL;i++){
		n=n->link;
	}
	if(n==NULL){
		cout<<"There are less than "<<pos<<" elements";
	}
	else{
		temp->link=n->link;
		n->link=temp;
 	}
	return head;
}

void display(Node *n){
	while(n != NULL){
		cout<<n->data<<" ";
		n=n->link;
	}
}

void count(Node *head){
	Node *n;
	int cnt=0;
	n=head;
	while(n!=NULL){
		n=n->link;
		cnt++;
	}
	cout<<"The number of elements in linked List is: "<<cnt<<endl;
}

void search(Node *head, int item){
	Node *n=head;
	pos=1;
	while(n!=NULL){
		if(n->data==item){
			cout<<"Item "<<item<<" found on position : "<<pos<<endl;
			return;
		}
		n=n->link;
		pos++;
	}
	cout<<"Item "<<item<<" not found in the list."<<endl;
}

Node *reverse(Node *head){
	Node *prev, *ptr, *next;
	prev=NULL;
	ptr=head;
	while(ptr!=NULL){
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	head=prev;
	return head;
}

Node *deleteNode(Node *head, int data){
	Node *n=head;
	Node *temp;
	if(head==NULL){
		cout<<"List is empty\n";
		return head;
	}
	if(head->data==data){
		temp=head;
		head=head->link;
		free(temp);
		return head;
	}
	while(n->link!=NULL){
		if(n->link->data==data){
			temp = n->link;
			n->link = temp->link;
			free(temp);
			return head;
		}
		n=n->link;
	}
	cout<<"Element "<<data<<" not found  in the list.";
	return head;
}

int main(){
	Node *head=NULL;
	int choice;
	while(1){
		cout<<"\n Enter 0 for Create list."<<endl;
		cout<<"\n Enter 1 for Insert element at beginning";
		cout<<"\n Enter 2 for Insert element at end";
		cout<<"\n Enter 3 for Insert element after a node";
		cout<<"\n Enter 4 for Insert element before a node";
		cout<<"\n Enter 5 for Insert element at position";
		cout<<"\n Enter 6 for Display elements";
		cout<<"\n Enter 7 for Count number of elements";
		cout<<"\n Enter 8 for Search an element";
		cout<<"\n Enter 9 for Delete an element";
		cout<<"\n Enter 10 for Reverse the list";
		cout<<"\n Enter 11 for Quit."<<endl;
		cout<<"\nEnter your choice:";
		cin>>choice;
		switch(choice){
			
			case 0:
				head=create(head);
			break;
							
			case 1: 
				cout<<"\nEnter the element to insert:";
				cin>>data;
				head=insertAtBeg(head,data);
			break;
			
			case 2:
				cout<<"Enter element to insert:";
				cin>>data;
				head=insertAtEnd(head,data);
			break;
			
			case 3:
				cout<<"Enter element to insert:";
				cin>>data;
				cout<<"Enter the item after which to insert:";
				cin>>item;
				head=insertAtAfterNode(head,data,item);
			break;
			
			case 4:
				cout<<"Enter the element to insert:";
				cin>>data;
				cout<<"Enter the element before which insert:";
				cin>>item;
				head=insertAtBeforeNode(head,data,item);
			break;
			
			case 5:
				cout<<"Enter the element to insert:";
				cin>>data;
				cout<<"Enter the position where to insert:";
				cin>>pos;
				head=insertAtPosition(head,data,pos);
			break;
			
			case 6:
				cout<<"\nList is:\n";
				display(head);
			break;
			
			case 7:
				count(head);
			break;
			
			case 8:
				cout<<"Enter the element to search:";
				cin>>item;
				search(head,item);
			break;
			
			case 9:
				cout<<"Enter the element to be deleted:";
				cin>>data;
				head=deleteNode(head,data);
			break;
			
			case 10:
				head=reverse(head);
			break;
			case 11:
				exit(1);
		
			default:
				cout<<"\nYou entered wrong choice.\nTry again..."; 
			}
	}
	return 0;
}
