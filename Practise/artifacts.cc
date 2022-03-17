#include<bits/stdc++.h>
using namespace std;

 int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> digged(n,vector<int>(n,0));
        int m = dig.size();
        int ans = 0;
        
        for(int i=0; i<m; i++){
            int r = dig[i][0], c = dig[i][1];
            digged[r][c] = 2;
        }
        
        for(int i=0; i<artifacts.size(); i++){
            int r1 = artifacts[i][0], c1 = artifacts[i][1];
            int r2 = artifacts[i][2], c2 = artifacts[i][3];
            bool flag = true;
            for(int row=r1; row<=r2; row++){
                for(int col=c1; col<=c2; col++){
                    if(digged[row][col] != 2){
                        flag = false;
                    }
                }
            }
            if(flag) ans += 1; 
        }
        return ans;
    }

int main(){
	int n, k;
	cin >> n;
	cin >> k;
	vector<vector<int>> artifacts(n,vector<int>(4,0));
	for(int i=0; i<n; i++){
		for(int j=0; j<4; j++) cin >> artifacts[i][j];
	}
	
	int m;
	cin >> m;
	vector<vector<int>> dig(m,vector<int>(m,0));
	for(int i=0; i<m; i++){
		for(int j=0; j<2; j++) cin >> dig[i][j];
	}
	
	return 0;
}
