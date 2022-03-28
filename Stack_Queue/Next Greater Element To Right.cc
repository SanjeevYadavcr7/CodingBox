#include<bits/stdc++.h>
using namespace std;

void display(vector<int>& arr){
	for(int& i : arr) cout << i << " ";
	cout << "\n";
}

vector<int> getNextGreater(vector<int>& arr){
	int n = arr.size(), i = n-1;
	vector<int> res(n);
	stack<int> stk;
	
	while(i>=0){
		if(stk.empty()){
			res[i] = -1;
			stk.push(i--);
		}
		else{
			while(!stk.empty() && arr[i] > arr[stk.top()]) stk.pop();
			if(stk.empty()){
				res[i] = -1;
				stk.push(i--);			
			}
			else{
				res[i] = arr[stk.top()];
				stk.push(i--);
			}
		}
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	vector<int> res = getNextGreater(arr);
	display(res);
	
	return 0;
}
