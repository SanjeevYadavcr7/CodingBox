#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>>& arr);

bool areEqualSubsets(vector<int>& subset_sum){
	int n = subset_sum.size();
	for(int i=1; i<n; i++){
		if(subset_sum[i] != subset_sum[i-1]) return false;
	}
	return true;
}

void getSubsetSum(int idx, vector<int>& arr, int curr_sets, int total_sets, vector<int>& set_sum, vector<vector<int>>& sets){
	if(idx == arr.size()){
		if(curr_sets == total_sets){
			if(areEqualSubsets(set_sum)) display(sets);
		}
		return;
	}
	
	for(int i=0; i<sets.size(); i++){
		if(sets[i].size() > 0){
			sets[i].push_back(arr[idx]);
			set_sum[i] += arr[idx];
			getSubsetSum(idx+1,arr,curr_sets,total_sets,set_sum,sets);
			sets[i].pop_back();	
			set_sum[i] -= arr[idx];
		}
		else{
			sets[i].push_back(arr[idx]);
			set_sum[i] += arr[idx];
			getSubsetSum(idx+1,arr,curr_sets+1,total_sets,set_sum,sets);
			sets[i].pop_back();	
			set_sum[i] -= arr[idx];
			break;
		}
	}
	
}

void getEqualSubsets(vector<int>& arr, int k){
    int n = arr.size(), sum = 0;

    for(int &i : arr) sum += i;
    if(n < k || sum % k != 0) cout << "-1";

	vector<int> set_sum(k,0);
    vector<vector<int>> subsets(k);
    getSubsetSum(0,arr,0,k,set_sum,subsets);
}


int main(){
    int n,k;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    cin >> k;

    getEqualSubsets(arr,k); 

    return 0;
}





























void display(vector<vector<int>>& arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        cout << "[";
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j];
            if(j < arr[i].size()-1) cout << ", ";
        }
        cout << "] ";
    }
    cout << "\n";
}
