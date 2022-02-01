#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        int max_profit = INT_MIN, min_price = INT_MAX;
        
        for(int curr_price : prices){
            min_price = min(curr_price, min_price);
            int curr_profit = curr_price - min_price;
            max_profit = max(max_profit,curr_profit);
        }
        
        return max_profit;
    }
};

int main(){
	int n;
	cin >> n;
	vector<int> prices(n,0);
	for(int i=0; i<n; i++) cin >> prices[i];
	
	Solution obj;
	int max_profit = obj.maxProfit(prices);
	cout << max_profit << "\n";
	
	return 0;
}
