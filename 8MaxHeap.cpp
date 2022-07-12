#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;


void display(vector<int> &mh){
    for(int i=0;i<mh.size();++i){
        cout<<mh[i]<<" " ;
    }
    cout<<endl;
    return;
}
void heapify(vector<int> &mh,int i){
    int n = mh.size();
    int lar = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && mh[l]>mh[lar]){
        lar = l;
    }
     if(r<n && mh[r]>mh[lar]){
        lar = r;
    }
    if(lar != i){
        int temp = mh[i];
        mh[i] = mh[lar];
        mh[lar] = temp;
        heapify(mh,lar);
    }
}

void insertMax(vector<int> &mh,int key){
    int n = mh.size();
    if(n == 0){
        mh.push_back(key);
    }
    else{
        mh.push_back(key);
        for(int i=n-1;i>=0;i--){
            heapify(mh,i);
        }
    }
}

void deleteMax(vector <int> &mh,int value){
    int n = mh.size();
    int i;
    for(i=0;i<n;i++){
        if(value == mh[i]){
            break;
        }
    }
    int temp = mh[i];
    mh[i] = mh[n-1];
    mh[n-1] = temp;
    mh.pop_back();
    for(int i=n-1;i>=0;i--){
        heapify(mh,i);
    }
}

int main(){
    vector <int> mh;

//    insertMax(mh,45);
//    insertMax(mh,15);
//    insertMax(mh,10);
//    insertMax(mh,29);
//    insertMax(mh,1);
//    insertMax(mh,46);
//    insertMax(mh,20);
//    insertMax(mh,30);
//    display(mh);
//    deleteMax(mh,15);
//    display(mh);

    int choice;
    do{
        cout<<"1. insert in Max heap"<<endl;
        cout<<"2. delete from the Max heap"<<endl;
        cout<<"3. Display The Max heap"<<endl;
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
            insertMax(mh,data);
            cout<<endl;
            break;

        case 2:
            int value;
            cout<<"Enter the value: ";
            cin>>value;
            deleteMax(mh,value);
            cout<<endl;
            break;

        case 3:
            display(mh);
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
