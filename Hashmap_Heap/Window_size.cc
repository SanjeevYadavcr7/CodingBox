#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> &arr, int k){
    int n = arr.size();
	vector<int> res;
	unordered_map<int,int> freq;

	for(int i=0; i<k; i++) freq[arr[i]] += 1;
	res.push_back(freq.size());

	for(int i=1; i<=n-k; i++) {
		freq[arr[i-1]] -= 1;
		if(freq[arr[i-1]] == 0) freq.erase(arr[i-1]);
		freq[arr[i+k-1]] += 1;
		res.push_back(freq.size());
	}
	return res;
}

int main (){
	int n = 0;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < arr.size(); i++){
	    cin >> arr[i];
	}
	int k = 0;
	cin >> k;
	
	vector<int> ans = solution(arr, k);
	for(int a : ans) cout << a << " ";
 
	return 0;
}

