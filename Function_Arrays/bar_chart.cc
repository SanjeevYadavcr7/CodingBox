#include<bits/stdc++.h>
using namespace std;

void printBarChart(int arr[], int max_num, int n){
	for(int i=max_num;i>0;i--){
		for(int j=0;j<n;j++){
			if(arr[j] >= i) cout<<"* ";
			else cout<<"  ";
		}
		cout<<"\n";
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n], max_num=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		max_num = max(max_num, arr[i]);
	} 
	printBarChart(arr, max_num, n);
	return 0;
}
