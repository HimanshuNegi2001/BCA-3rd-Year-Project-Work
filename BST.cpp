#include<iostream>
#include<queue>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};
node *GetNewNode(int data)
{
	node *NewNode=new node();
	NewNode->data=data;
	NewNode->left=NULL;
	NewNode->right=NULL;
	return NewNode;
}
node *Insert(node *root,int data)
{
	if(root==NULL)
	{
		root=GetNewNode(data);
	}
	else if(data<=root->data)
	{
		root->left=Insert(root->left,data);
	}
	else if(data>=root->data)
	{
		root->right=Insert(root->right,data);
	}
	else
	cout<<"duplicate key\n";
	return root;
}
void preorder(node *root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void inorder(node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);	
}
void postorder(node *root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
void levelorder(node *root)
{
	if(root==NULL)
	return;
	queue<node*> Q;
	Q.push(root);
	while(!Q.empty())
	{
		node* current=Q.front();
		cout<<current->data<<" ";
		
		if(current->left!=NULL)
			Q.push(current->left);
		if(current->right!=NULL)
			Q.push(current->right);
		Q.pop();
	}
}
void findmin(node *root)
{
	if(root==NULL)
	{
		cout<<"Tree is empty\n";
		return;
	}
	node *current=root;
	while(current->left!=NULL)
	{
		current=current->left;
	}
	cout<<"minimum value is "<<current->data<<endl;
}
void findmax(node *root)
{
	if(root==NULL)
	{
		cout<<"Tree is empty\n";
		return;
	}
	node *current=root;
	while(current->right!=NULL)
	{
		current=current->right;
	}
	cout<<"Maximum value is "<<current->data<<endl;
}
int findheight(node *root)
{
	if(root==NULL)
		return -1;
	int height,hleft,hright;
	hleft=findheight(root->left);
	hright=findheight(root->right);
	if(hleft>hright)
	{
	  height=hleft;
	}
	else
	   height=hright;
	   return height+1;
}

node *findmaxad(node *root)
{
	while(root->right!=NULL)
	root=root->right;
	return root;
}
node *deletenode(node *root,int data)
{
	node *temp;
	if(root==NULL)
		return NULL;
	
	else if(data>root->data)
		root->right=deletenode(root->right,data);
		
	else if(data<root->data)
		root->left=deletenode(root->left,data);	
		
	else
	{
		//CASE 1: 2 CHILDREN
		if(root->right&&root->right)
		{
			temp=findmaxad(root->left);
			root->data=temp->data;
			root->left=deletenode(root->left,root->data);
		}
		//CASE 2: 1 CHILDREN
		else if(root->left==NULL)
		{
			temp=root;
			root=root->right;
			delete temp;		
		}
		else if(root->right==NULL)
		{
			temp=root;
			root=root->left;
			delete temp;
		}
		//CASE 3: NO CHULDREN
		else
		{
			delete root;
			root=NULL;
		}
	}	
	return root;
}
main()
{
	node *root;
	root=NULL;
	int choice,data;
	
	while(1)
	{
		cout<<"\n1=Insert value\n";
		cout<<"2=Preoreder traversal\n";
		cout<<"3=Inorder traversal\n";
		cout<<"4=Postoerder traversal\n";
		cout<<"5=Level order traversal\n";
		cout<<"6=Find minimum\n";
		cout<<"7=Find maximum\n";
		cout<<"8=Find height\n";
		cout<<"9=elete\n";
		cout<<"\nEnter your choice\n";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"Enter the item to be inserted\n";
				cin>>data;
				root=Insert(root,data);
				break;
			case 2:
				preorder(root);	
				break;
			
			case 3:
				inorder(root);
				break;
				
			case 4:
				postorder(root);		
				break;
			
			case 5:
				levelorder(root);
				break;
				
			case 6:
				findmin(root);
				break;	
			
			case 7:
				findmax(root);
				break;		
				
			case 8:
				int height;
				height=findheight(root);
				cout<<"height of tree is "<<height<<endl;
				break;
				
			case 9:
				cout<<"Enter the number to be deleted\n";
				cin>>data;
				root=deletenode(root,data);
				break;
						 
			default:
					cout<<"Error:Wrong choice\n";		
		}	
	}
}
