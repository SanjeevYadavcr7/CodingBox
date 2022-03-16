class Solution
{
    public:
    vector<vector<int>> ans;
    
    void solve(int idx, vector<int>& arr, vector<int> subset){
        if(idx == arr.size()){
            ans.push_back(subset);
            return;
        }
        
        solve(idx+1,arr,subset);
        subset.push_back(arr[idx]);
        solve(idx+1,arr,subset);
    }
    
    vector<vector<int> > subsets(vector<int>& A){
        vector<int> subset;
        solve(0,A,subset);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

