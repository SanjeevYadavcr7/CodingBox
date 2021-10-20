#include<iostream>
using namespace std;

void whoWins(int *arr, int n){
	int india_won = 0, eng_won = 0;
	for(int i=0;i<n;i++){
		if(arr[i] == 1) india_won++;
		else if(arr[i] == 2) eng_won++;
		else continue;
	}
	
	if(eng_won == india_won) cout<<"DRAW\n";
	else if(eng_won > india_won) cout<<"ENGLAND\n";
	else cout<<"INDIA\n";
}	

int main(){
	int t;
	cin>>t;
	while(t--){
		int n = 5;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		whoWins(arr,n);
	}
	return 0;
}
