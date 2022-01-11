#include<bits/stdc++.h>
using namespace std;

void doTransaction(int arr[], int n){
	int mp_if_sold_today = 0;
	int least_buy = arr[0];
	vector<int> dp1(n);
	for(int i=1;i<n;i++){
		least_buy = min(arr[i],least_buy);
		mp_if_sold_today = arr[i] - least_buy;
		dp1[i] = max(dp1[i-1],mp_if_sold_today);
	}
	
	int mp_if_bought_today = 0;
	int max_sold = arr[n-1];
	vector<int> dp2(n);
	for(int i=n-2;i>=0;i--){
		max_sold = max(arr[i],max_sold);
		mp_if_bought_today = max_sold - arr[i];
		dp2[i] = max(dp2[i+1],mp_if_bought_today);
	}
	
	int max_profit = 0;
	for(int i=0;i<n;i++){
		max_profit = max(max_profit, dp1[i]+dp2[i]);
	}
	cout << max_profit << "\n";
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++) cin >> arr[i];
	
	doTransaction(arr,n);

	return 0;
}
