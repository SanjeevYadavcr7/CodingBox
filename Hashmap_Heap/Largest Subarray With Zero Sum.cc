#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> arr) {
	int max_len = 0;
	int pre_sum = 0;
	int n = arr.size();	
	unordered_map<int,int> last_seen;
	
	for(int i=0; i<n; i++) {
		pre_sum += arr[i];
		if(pre_sum == 0) {
			max_len = i+1;
			continue;
		}
		if(last_seen[pre_sum] > 0) {
			int curr_len = i - (last_seen[pre_sum]-1);
			max_len = max(max_len,curr_len);
		}
		else last_seen[pre_sum] = i+1;
	}
	return max_len;
}

int main() {
  int n;
  cin >> n;
  vector<int>arr(n, 0);
  for (int i = 0; i < n; i++) cin >> arr[i];
  cout << solution(arr) << endl;
  return 0;
}
