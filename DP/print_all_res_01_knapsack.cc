#include<bits/stdc++.h>
using namespace std;

struct customPair{
    int x;
    int y;
    string path;
    customPair(int x, int y, string path){
        this->x = x;
        this->y = y;
        this->path = path;
    }
};

void printMaxProfitPath(vector<int>& price, vector<int>& weight, vector<vector<int>>& dp){
    int n = dp.size(), m = dp[0].size();
    queue<customPair*> Q;

    Q.push(new customPair(n-1,m-1,""));
    while(!Q.empty()){
        int size = Q.size();
        while(size--){
            auto it = Q.front();
            int x = it->x;
            int y = it->y;
            string path = it->path;
            Q.pop();

            if(x == 0 || y == 0){
                cout << path << "\n";
                continue;
            }

            int exc_price = dp[x-1][y];
            if(y >= weight[x-1]){
                int inc_price = dp[x-1][y-weight[x-1]] + price[x-1];
                if(inc_price == dp[x][y]) Q.push(new customPair(x-1,y-weight[x-1],to_string(x-1)+" "+path));
            }

            if(exc_price == dp[x][y]) Q.push(new customPair(x-1,y,path));
        }
    }
} 

void getMaxProfit(vector<int>& price, vector<int>& weight, int cap){
    int n = price.size();
    vector<vector<int>> dp(n+1,vector<int>(cap+1,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=cap; j++){
            if(j < weight[i-1]) dp[i][j] = dp[i-1][j];
            else{
                int max_price = max(dp[i-1][j], price[i-1]+dp[i-1][j-weight[i-1]]);
                dp[i][j] = max_price;
            }
        }
    }
    cout << dp[n][cap] << "\n";
    printMaxProfitPath(price,weight,dp);
}

int main(){
    int n, cap; 
    cin >> n;
    vector<int> arr(n,0);
    vector<int> weight(n,0);
    
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n; i++) cin >> weight[i];
    cin >> cap;

    getMaxProfit(arr,weight,cap);
 
    return 0;
}