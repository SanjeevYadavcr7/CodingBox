#include<iostream>
using namespace std;

void visitWakanda(int** arr, int n){
	int min_r=0, min_c=0, max_r=n-1, max_c=n-1;
	
	while(true){
		for(int i=min_r,j=min_c; i<=max_r,j<=max_c; i++,j++){
			cout<<arr[i][j]<<"\n";
		}
		min_c++;
		if(min_c > max_c) break;
	}
	cout<<"\n";
}

int main(){
	int n;
	cin>>n;
	int** arr = new int*[n];
	for(int i=0;i<n;i++) arr[i] = new int[n];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin>>arr[i][j];
	
	visitWakanda(arr, n);
		
	return 0;
}
