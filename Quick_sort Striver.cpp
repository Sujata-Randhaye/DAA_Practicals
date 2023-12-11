#include<iostream>

using namespace std;
int partition(int a[],int low,int high)
{
	int pivot=a[low];
	int i=low;
	int j=high;
	while(i<j)
	{
		while(a[i]<=pivot && i<=high)
		{
			i++;
		}
		while(a[j]>pivot && j>=low)
		{
			j--;
		}
		if(i<j)
		{
			swap(a[i],a[j]);
		}
	}
	swap(a[low],a[j]);
	return j;
	
}
void quick_sort(int a[],int low,int high)
{
	if(low>=high)
	return ;
		int pivotindex=partition(a,low,high);
			quick_sort(a,low,pivotindex-1);
			quick_sort(a,pivotindex+1,high);
}

int main(){
	int a[50];
	int n;
	cout<<"Enter size of array:";
	cin>>n;
	cout<<"Enter the elements in array:";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int s=0;
	int e=n-1;
	quick_sort(a,s,e);
	
	cout<<"The sorted array is:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}

	return 0;
}





