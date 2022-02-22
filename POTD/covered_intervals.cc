#include<bits/stdc++.h>
using namespace std;

bool sortIntervals(vector<int>& interval1, vector<int>& interval2){
    if(interval1[0] == interval2[0]) return interval1[1] < interval2[1];
    return interval1[0] < interval2[0]; 
} 

bool isOverlappingInterval(int b1, int e1, int b2, int e2){
    if(((b1 <= b2) && (b2 <= e1)) && ((b1 <= e2) && (e2 <= e1))) return true;
    return false;
}


int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    stack<vector<int>> stk;
    sort(intervals.begin(),intervals.end(),sortIntervals);
    stk.push(intervals[0]);

    for(int i=1; i<n; i++){
        vector<int> it = stk.top();
        int prev_beg = it[0], prev_end = it[1];
        int curr_beg = intervals[i][0], curr_end = intervals[i][1];

        if(isOverlappingInterval(prev_beg, prev_end, curr_beg, curr_end)) continue;
        if(isOverlappingInterval(curr_beg, curr_end, prev_beg, prev_end)) stk.pop();
        stk.push(intervals[i]);    
    }
    return stk.size();
}

int main(){
    int n; 
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(2,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++) cin >> arr[i][j];
    }

    int rem_intervals = removeCoveredIntervals(arr);
    cout << rem_intervals << "\n";

    return 0;
}