class Solution {
public:
    int countVowelStrings(int n) {
        int cnt = 1;
        if(n == 1) return 5;
        vector<vector<int>> dp(n+1,vector<int>(5));
        
        for(int j=0; j<5; j++) {
            dp[0][j] = 0;
            dp[1][j] = 1;
        }
        
        for(int i=2; i<=n; i++) {
            dp[i][0] = 1;
            for(int j=1; j<5; j++) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];   
                if(i == n) cnt += dp[i][j];
            }
        }
        
        return cnt;
    }
};
