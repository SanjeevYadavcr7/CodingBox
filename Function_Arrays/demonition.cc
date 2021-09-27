#include<iostream>
using namespace std;

void get_notes(int* arr, int n, int item){
	
	int beg = 0, end = n-1;
	bool found = false;
	while(beg <= end){
		int mid = (beg+end)/2;
		if(arr[mid] == item){
			found = true;
			break;
		}
		else if(arr[mid] > item){
			end = mid-1;
		}
		else{
			beg = mid+1;
		}
	}
	if(found) cout<<item;
	else cout<<arr[beg]<<"\n"<<arr[end];
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int item;
	cin>>item;
	get_notes(arr, n, item);
	
	return 0;
}
