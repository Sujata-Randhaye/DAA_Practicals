//In sorted array

#include<iostream>
#include<vector>
using namespace std;

int binary_search(int a[],int n,int item)
{
	int l=0;
	int h=n-1;
	while(l<=h)
	{
		int mid=(l+h)/2;
		if(a[mid]==item)
		return mid;
		else if(item>a[mid])
		l=mid+1;
		else
		h=mid-1;
	}
	return -1;
}
int main()
{
	int arr[]={1,2,3,4,5};
	int n=5;
	int item;
	cout<<"Enter item:";
	cin>>item;
	int pos=binary_search(arr,n,item);
	if(pos==-1)
	{
		cout<<"element not found!!";
	}
	else
	cout<<"Element "<<item<<" found at "<<pos<<" th position";
	return 0;
}
