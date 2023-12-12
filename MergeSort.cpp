#include<iostream>
using namespace std;
void merge(int arr[], int low, int mid, int high) {
int temp[50]; // temporary array
int left = low; // starting index of left half of arr
int right = mid + 1; // starting index of right half of arr
int k=0;
while (left <= mid && right <= high) 
{
if (arr[left] <= arr[right])
{
	temp[k++]=arr[left++];
}
else {
	temp[k++]=arr[right++];
}
}
// if elements on the left half are still left
while (left <= mid) {
temp[k++]=arr[left++];
}
// if elements on the right half are still left //
while (right <= high) {
temp[k++]=arr[right++];
}
// transfering all elements from temporary to arr //
for (int i = low, j=0; i <= high; i++,j++) {
arr[i] = temp[j];
}
}
void mergeSort(int arr[], int low, int high) {
if (low >= high) return;
int mid = (low + high) / 2 ;
mergeSort(arr, low, mid); // left half
mergeSort(arr, mid + 1, high); // right half
merge(arr, low, mid, high); // merging sorted halves
}
int main() {
int arr[50];
int n;
cout<<"Enter size of array:";
cin >> n;
cout<<"Enter the elements of array:";
for(int i=0; i<n; i++){
cin >> arr[i];
}
 mergeSort(arr, 0, n - 1);
cout << "Sorted array: ";
for (int i = 0; i < n; i++) {
cout << arr[i] << " " ;
}
cout << endl;
return 0 ;
}


