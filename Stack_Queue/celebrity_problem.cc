#include<bits/stdc++.h>
using namespace std;

void findCelebrity(vector<string> arr, int n){
	stack<int> s;
	for(int i=n-1;i>=0;i--) s.push(i);
	int ans=-1;
	for(int i=0;i<n;i++){
		stack<int> temp = s;
		int flag = 1;
		while(!temp.empty()){
			if(arr[i][temp.top()] != '0'){
				flag = 0;
				break;
			} 
			if(i != temp.top() && arr[temp.top()][i] != '1'){
				flag = 0;
				break;
			} 
			temp.pop();
		}
		if(flag){
			ans = i;
			break;
		} 
	}
	if(ans == -1) cout<<"none\n";
	else cout<<ans<<"\n";
}

int main(){
	int n;
	cin>>n;
	string str;
	vector<string> arr;
	for(int i=0;i<n;i++){
		cin>>str;
		arr.push_back(str);
	}

	findCelebrity(arr,n);
	return 0;
}
