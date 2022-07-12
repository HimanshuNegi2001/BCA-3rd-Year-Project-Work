#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * TreeCreate(int key){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};

struct Node * TreeInsert(struct Node* root,int key){
    if(root==NULL){
        return TreeCreate(key);
    }
    else if(root->data > key){
        root->left = TreeInsert(root->left,key);
    }
    else{
        root->right = TreeInsert(root->right,key);
    }
    return root;
};

struct Node *inOrderPredecessor(struct Node* root){
    root = root->left;
    while (root->right!=NULL){
        root = root->right;
    }
    return root;
}
struct Node *inOrderSuccessor(struct Node* root){
    root = root->right;
    while (root->left!=NULL){
        root = root->left;
    }
    return root;
}

struct Node *deleteNode(struct Node *root, int value){
    struct Node* iPre;
    if (root == NULL){
        cout<<"Tree is empty"<<endl;
        return root;
    }
    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }
    else{
        if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
        }
        else if(root->right != NULL){
            iPre = inOrderSuccessor(root);
            root->data = iPre->data;
            root->right = deleteNode(root->right,root->data);
        }
        else{
            iPre = inOrderPredecessor(root);
            root->data = iPre->data;
            root->left = deleteNode(root->left,root->data);
        }
    }
    return root;
}

struct Node *searching(struct Node *root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    else if(root->data>key){
        return searching(root->left,key);
    }
    else{
        return searching(root->right,key);
    }
};


void inorder(struct Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    struct Node *root = NULL;
    struct Node *n;
//    root = TreeInsert(root,89);
//    root = TreeInsert(root,19);
//    root = TreeInsert(root,34);
//    root = TreeInsert(root,14);
//    root = TreeInsert(root,98);
//
//    inorder(root);
//    root = deleteNode(root,19);
    //root = deleteNode(root,89);
    //cout<<endl;
    //inorder(root);
    //root = searching(root,981);

    int choice;
    do{
        cout<<"1. Insertion in Tree"<<endl;
        cout<<"2. Searching in a Tree"<<endl;
        cout<<"3. Deletion in Tree"<<endl;
        cout<<"4. Display The Tree"<<endl;
        cout<<"0. For Exit"<<endl;
        cout<<"ENTER THE CHOICE : ";
        cin>>choice;
        switch(choice){
        case 0:
            break;
        case 1:
            int data;
            cout<<"Enter the data: ";
            cin>>data;
            root = TreeInsert(root,data);
            cout<<endl;
            break;

        case 2:
            int key;
            cout<<"Enter the value for Searching : ";
            cin>>key;
            n = searching(root,key);
            if(n!=NULL){
                cout<<"Found: "<<n->data<<endl;
            }
            else{
                cout<<key<<" is not present in tree"<<endl;
            }
            cout<<endl;
            break;

        case 3:
            int value;
            cout<<"Enter the value for Deletion : ";
            cin>>value;
            root = deleteNode(root,value);
            cout<<endl;
            break;

        case 4:
            inorder(root);
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
