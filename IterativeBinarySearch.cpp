#include<bits/stdc++.h>
using namespace std;
#define MAX 20

int binarySearch(int arr[], int n, int item){
	int low=0, up=n-1, mid;
	while(low<=up){
		mid = (low + up)/2;
		if(arr[mid] == item)
			return mid;
		else	if(arr[mid] < item)
					low = mid+1;
				else
					up = mid-1;
	}
	return -1;
}

int main(){
	int arr[MAX];
	int num,i,item;
	cout << "Enter the number of elements in array: ";
	cin >> num;
	cout << "Enter the numbers in sorted order:  ";
	for(i=0; i<num; i++){
		cin >> arr[i];
	}
	
	cout << "Entered array is : ";
	for(i=0;i<num;i++){
		cout << "  " << arr[i];
	}
	
	cout << "\nEnter the number to search : ";
	cin >> item;
	
	int result = binarySearch(arr, num, item);
	
	if(result == -1)
		cout << "Element is not present in array.";
	else
		cout << "Element is present at index: " << result;
	return 0;
}
