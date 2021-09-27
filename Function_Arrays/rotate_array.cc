#include<iostream>
using namespace std;

void reverse(int* arr, int beg, int end){
	while(beg<end){
		int temp = arr[beg];
		arr[beg] = arr[end];
		arr[end] = temp;
		beg++;
		end--;
	}
}

void rotate(int* arr, int n, int k){
   if(k == 0 || k%n == 0) return;
   k = k % n;
   if(k<0) k += n;
   reverse(arr, 0, n-k-1);
   reverse(arr, n-k, n-1);
   reverse(arr, 0, n-1);
}

void display(int* arr, int n){
    for(int i = 0 ; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n, r;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    cin>>r;
    
    rotate(arr,n,r);
    display(arr,n);
}
