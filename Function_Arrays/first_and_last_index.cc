#include<iostream>
using namespace std;

int binarySearch(int* arr, int n, int item){
	int beg = 0, end = n-1;
	while(beg <= end){
		int mid = (beg+end)/2;
		if(arr[mid] == item) return mid;
		else if(arr[mid] > item) end = mid-1;
		else beg = mid+1;
	}
	return -1;
}

void findIndexes(int* arr, int n, int item){	
	int index = binarySearch(arr, n, item);	
	int beg = index, end = index;
	while(beg>=0 && end<n){
		if(arr[end+1] == arr[beg-1] && (beg>=0 && end<n)){
			beg -= 1;
			end += 1;
		}
		else if(arr[end+1] == arr[beg]) end += 1;
		else if(arr[end] == arr[beg-1]) beg -= 1;
		else break;
	} 
	cout<<beg<<"\n"<<end<<"\n";
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int item;
	cin>>item;
	findIndexes(arr, n, item);
	return 0;
}
