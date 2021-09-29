#include<iostream>
using namespace std;

void rotateMatrix(int** arr, int n){
	int m = n;
	for(int i=0;i<n/2;i++){
		for(int j=0;j<m;j++){
			int temp = arr[i][j];
			arr[i][j] = arr[n-i-1][j];
			arr[n-i-1][j] = temp;
		}
	}
		
	for(int i=0;i<n;i++){
		for(int j=i;j<m;j++){
			int temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cout<<arr[i][j]<<" ";
		cout<<"\n";
	}
}

int main(){
	int n;
	cin>>n;
	int** arr = new int*[n];
	for(int i=0;i<n;i++) arr[i] = new int[n];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin>>arr[i][j];
	
	rotateMatrix(arr, n);
	return 0;
}
