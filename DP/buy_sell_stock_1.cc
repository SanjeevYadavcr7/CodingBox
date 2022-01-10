#include <bits/stdc++.h>
using namespace std;

void Transaction(vector<int> arr) {
	int least_buy = INT_MAX;
	int max_profit = INT_MIN;
	for(int i=0;i<arr.size();i++){
		least_buy = min(least_buy,arr[i]);
		int today_profit = arr[i] - least_buy; 
		max_profit = max(max_profit, today_profit);
	}
	cout<<max_profit<<"\n";
}

int main() {
 	int n;
 	cin >> n;
  	vector<int>arr(n, 0);
  	for (int i = 0; i < arr.size(); i++) cin >> arr[i];

  	Transaction(arr);
  
  	return 0;
}
