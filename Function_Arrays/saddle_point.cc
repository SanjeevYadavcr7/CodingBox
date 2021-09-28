#include<bits/stdc++.h>
using namespace std;

void findSaddlePoint(int** arr, int n){
	
	int min_r=0,min_c=0, max_r=n-1, max_c=n-1;
	int min_num = INT_MAX, max_num = INT_MIN;
	int flag = 0, k = 0, saddle=0;
	while(true){
	
		if(!flag){
			for(int i=0,j=k;i<=max_r;i++)
				max_num = max(max_num, arr[i][j]);	
			flag = 1;
		}
		for(int i=min_r,j=min_c;j<=max_c;j++)
			min_num = min(min_num, arr[i][j]);
		
		if(min_num == max_num){
			saddle = 1;
			break;
		} 
		else{
			min_r++;
			min_num = INT_MAX; 
			if(min_r > max_r){
				k++;
				flag = 0;
				min_r = 0;
				max_num = INT_MIN;
				if(k > max_c) break;	
			}
		} 
	}
	if(saddle) cout<<min_num;
	else cout<<"Invalid input";
	cout<<"\n";
	
}

int main(){
	int n;
	cin>>n;
	int** arr = new int*[n];
	for(int i=0;i<n;i++) arr[i] = new int[n];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin>>arr[i][j];
	
	findSaddlePoint(arr, n);
		
	return 0;
}
