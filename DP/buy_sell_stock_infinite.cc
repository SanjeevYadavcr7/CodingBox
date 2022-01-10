#include <bits/stdc++.h>
using namespace std;

void Transaction(vector<int> arr) {
	int buy = 0, sell = 0;
	int max_profit = 0;
	for(int i=1;i<arr.size();i++){
		if(arr[i] >= arr[sell]) sell = i;
		else{
			int profit = arr[sell] - arr[buy];
			max_profit += profit;
			buy = sell = i;
			//cout<<"Profit = "<<profit<<" | ";
		}
		//cout<<"Buy = "<<arr[buy]<<" | Sell = "<<arr[sell]<<"\n";
	}	
	int profit = arr[sell] - arr[buy];
	max_profit += profit;
	cout<< max_profit << "\n";
}

int main() {
 	int n;
 	cin >> n;
  	vector<int>arr(n, 0);
  	for (int i = 0; i < arr.size(); i++) cin >> arr[i];

  	Transaction(arr);
  
  	return 0;
}
