#include<iostream>
using namespace std;

void display(int* arr, int n){
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<"\n";
}

void reverse(int* arr, int n){
	for(int i=0;i<n/2;i++){
		int temp = arr[i];
		arr[i] = arr[n-i-1];
		arr[n-i-1] = temp;
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	reverse(arr, n);
	display(arr, n);
	return 0;
}


