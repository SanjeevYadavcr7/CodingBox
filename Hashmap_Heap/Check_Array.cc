#include<bits/stdc++.h>
using namespace std;

bool solution(vector<int> &arr, int k){
	unordered_map<int,int> freq;
	
	for(int i : arr) {
		int num = ((i % k) + k) % k;
		freq[num] += 1;
	}
	
	for(auto i : freq) {
		int curr_num = i.first;
		int req_num = k - curr_num;
		if(curr_num == 0) {
			if(freq[curr_num] % 2 != 0) return false;
		}
		else {
			if(freq[curr_num] != freq[req_num]) return false;
		}
	}
	return true;
}

int main() {
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	cout << (solution(arr,k) ? "true" : "false") << endl;

	return 0;
}
