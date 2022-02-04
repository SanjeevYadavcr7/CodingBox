#include<bits/stdc++.h>
using namespace std;

int getDistanceFromOrigin(int x, int y){
    return (x*x + y*y);
}    

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) { 
    int n = points.size(), cnt = 0;
    multimap<int,int> mp;
    for(int i=0; i<n; i++){
        int dis = getDistanceFromOrigin(points[i][0],points[i][1]);
        mp.insert({dis,i});    
    }

    vector<vector<int>> ans;
    for(auto it = mp.begin(); cnt<k; it++,cnt++){
        ans.push_back(points[it->second]);
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