#include<iostream>
using namespace std;
#define MAX 100
void quick(int arr[],int low,int up);
int partition(int arr[],int low,int up);

int main(){
int array[MAX];
int i,n=5;

cout << "Enter the number of elements: " ;
cin >> n;
cout << "Enter elements :\n" ;
for(i=0;i<n;i++)
{
	cin >> array[i];
}

quick(array,0,n-1);

cout << "\nSorted list is:\n" ;
for(i=0;i<n;i++){
	cout <<" " << array[i] ;
}
return 0;
}

void quick(int arr[],int low,int up){
	int pivloc;
	if(low>=up)
		return;
	pivloc = partition(arr,low,up);
	quick(arr,low,pivloc-1);
	quick(arr,pivloc+1,up);
	}

int partition(int arr[],int low,int up){
	int temp,i,j,pivot;
	i = low+1;
	j = up;
	pivot = arr[low];
	while(i <= j)
	{
		while((arr[i] < pivot) && (i < up))
			i++;
		while(arr[j] > pivot)
			j--;
		if(i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
		else
			i++;
	}
	arr[low] = arr[j];
	arr[j] = pivot;
	return j;

}
