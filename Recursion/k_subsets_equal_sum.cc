#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>> ans);

vector<vector<int>> kEqualSubsets(vector<int>& arr, int k){

}

int main(){
	int n,k;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	cin >> k;
	
	vector<vector<int>> ans = kEqualSubsets(arr,k);
	display(ans);
	
	return 0;
}












































void display(vector<vector<int>> ans){
	for(int i=0; i<ans.size(); i++){
		cout << "[";
		for(int j=0; j<ans[0].size(); j++){
			cout << ans[i][j];
			if(j != ans[i].size()) cout << ", ";
		}
		cout << "] ";
	}
}
