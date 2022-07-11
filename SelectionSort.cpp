#include<iostream>
using namespace std;

int minElement(int arr[], int i){
	int min = i;
	for(int j=i+1; j<8; j++){
		if(arr[min] > arr[j]){
			min = j;
		}
	}
	return min;
}

int main(){
	int i;	
	int arr[] = {34, 23, 54, 12, 45, 32, 94, 10};

	cout << "Array is: " << endl;
	for(i=0; i<8; i++){
		cout << "\t" << arr[i];
	}
	
	
	for(i=0; i<8; i++){
		int min = minElement(arr, i);
		if(i!=min){
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}

	
	cout << "\nSorted array is: " << endl;

	for(i=0; i<8; i++){
		cout << "\t" << arr[i];
	}
}
