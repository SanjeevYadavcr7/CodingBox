#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> arr) {
	int res = 0;
	int pre_sum = 0;
	int n = arr.size();	
	unordered_map<int,int> freq;
	
	freq[0] = 1;
	for(int i=0; i<n; i++) {
		pre_sum += arr[i];
		if(freq[pre_sum] > 0) res += freq[pre_sum];
		freq[pre_sum] += 1;
	}
	
	return res;
}

int main() {
	  int n;
	  cin >> n;
	  vector<int>arr(n, 0);
	  for (int i = 0; i < n; i++) cin >> arr[i];
	  cout << solution(arr) << endl;
	  return 0;
}
