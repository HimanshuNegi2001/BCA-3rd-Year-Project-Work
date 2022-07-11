#include<iostream>
using namespace std;
int kadanes(int array[],int length) {
   int highestMax = 0;
   int currentElementMax = 0;
   for(int i = 0; i < length; i++){
      currentElementMax =max(array[i],currentElementMax + array[i]) ;
      highestMax = max(highestMax,currentElementMax);
   }
   return highestMax;
}
int main() {
   cout << "Array Length: ";
   int l;
   cin >> l;
   int arr[l];
   cout << "Enter the elements: ";
   for (int i = 0; i < l; i++) {
      cin >> arr[i];
   }
   cout << "Maximum Sum is: "<<kadanes(arr,l) << endl;
   return 0;
}
