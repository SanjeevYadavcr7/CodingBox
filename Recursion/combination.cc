#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<char>>& arr);

vector<vector<char>> ans;

void getCombinations(int idx, int cnt, int k, int n, vector<char>& temp){
	if(idx == n || cnt >= k){
		if(cnt == k){
			ans.push_back(temp);
		}
		return;
	}
	
	
	for(int j=idx+1; j<n; j++){
		temp[j] = 'i';
		getCombinations(j,cnt+1,k,n,temp);
		temp[j] = '-';
	}
}

vector<vector<char>> combine(int n, int k){

	for(int i=0; i<=n-k; i++){
		vector<char> temp(n,'-');
		if(k == 0){
			ans.push_back(temp);
			return ans;
		}
		temp[i] = 'i'; 
		getCombinations(i,1,k,n,temp);
	}	
	return ans;
}

int main(){
	int n,r;
	cin >> n >> r;
	
	vector<vector<char>> nCr = combine(n,r);
	display(nCr);

	return 0;
}











































void display(vector<vector<char>>& arr){
	int n = arr.size(), m = arr[0].size();
	for(int i=0; i<n; i++){
		//cout << "[";
		for(int j=0; j<m; j++){
			cout << arr[i][j] << "";
			//if(j != m-1) cout << ", ";
		}
		cout << "\n";
	}
}
