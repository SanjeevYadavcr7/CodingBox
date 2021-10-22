#include<bits/stdc++.h>
using namespace std;

int getCelebrity(int** arr, int n){
	stack<int> s;
	for(int i=0;i<n;i++) s.push(i);
	
	int pot_cel;
	while(s.size() > 1){
		int i = s.top();
		s.pop();
		int j = s.top();
		s.pop();
	
		if(arr[i][j] == 1) pot_cel = j;
		else pot_cel = i;
		s.push(pot_cel);
	}
	
	int ans = pot_cel;
	for(int i=0;i<n;i++){
		if(i != pot_cel){
			if(arr[pot_cel][i] == 1 || arr[i][pot_cel] == 0){
				ans = -1;
				break;
			}
		}
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	int** arr = new int*[n];
	for(int i=0;i<n;i++) arr[i] = new int[n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin>>arr[i][j];
	}
	
	
	int ans = getCelebrity(arr, n);
	if(ans == -1) cout<<"none\n";
	else cout<<ans<<"\n";
	
	return 0;
}
