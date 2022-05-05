#include<bits/stdc++.h>
using namespace std;

namespace x{
	int min,max;
}

int getLargestContiguousArray(vector<int>& arr) {
	int n = arr.size();
	int max_len = 0;
	
	for(int i=0; i<n; i++) {
		x::max = INT_MIN, x::min = INT_MAX;
		int idx = 0;
		unordered_map<int,bool> freq;
		for(int j=i; j<n; j++) {
			if(freq[arr[j]]) break;
            freq[arr[j]] = true;
			x::max = max(x::max,arr[j]);
			x::min = min(x::min,arr[j]);
			if(x::max - x::min == j-i && j-i == freq.size()-1) max_len = max(max_len,j-i+1);
		}
	}
	return max_len;
}

int main() {	
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	int len = getLargestContiguousArray(arr);
 	cout << len << endl;
 	
	return 0;
}
