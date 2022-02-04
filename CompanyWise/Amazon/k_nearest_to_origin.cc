#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
    
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size(), m = points[0].size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            int dis = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            mp[i] = dis;
        }
        
        vector<pair<int,int>> arr;
        for(auto it : mp) arr.push_back(it);
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end(), cmp);
        auto it = arr.begin();
        for(auto it:arr){
            int idx = it.first;
            vector<int> temp = {points[idx][0], points[idx][1]};
            ans.push_back(temp);
            k--;
            if(k == 0) break;
        }
        
        return ans;
}


int main(){
    int n, m = 2, k;
    cin >> n >> k;
    vector<vector<int>> points(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++) cin >> points[i][j];
    }

    vector<vector<int>> ans = kClosest(points,k);    
    for(auto i : ans){
        cout << "(";
        for(int j : i) cout << j << " ";
        cout << ") ";
    }
    cout << "\n";

    return 0;
}