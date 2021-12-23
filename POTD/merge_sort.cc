#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int beg, int mid, int end){
	int temp[end-beg+1];
	int i=beg,j=mid+1,k=0;
	while(i<=mid && j<=end){
		if(arr[i] < arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}
	
	while(i<=mid) temp[k++] = arr[i++];
	while(j<=end) temp[k++] = arr[j++];
	for(int x=beg;x<=end;x++) arr[x] = temp[x-beg];
}

void mergeSort(int arr[], int l, int r){
	if(l<r){
		int mid = (l+r)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	mergeSort(arr,0,n-1);	
	
	cout<<"\narr[] = ";
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<"\n";
	return 0;
}
