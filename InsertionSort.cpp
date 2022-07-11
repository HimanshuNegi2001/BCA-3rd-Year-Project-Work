#include<iostream>
using namespace std;

int main(){
	int arr[]= {83, 20, 10, 30, 15, 40, 93, 11};
	int n=8; 
	int i,j,k;
	for(i=1; i<n; i++){
		k = arr[i];
		for(j=i-1; j>=0 && k<arr[j]; j--){
			arr[j+1] = arr[j];
		}
		arr[j+1] = k;
	}
	
	cout << "\nSorted array is : ";
	for(i=0; i<8; i++){
		cout << "\t" << arr[i];
	}
}
