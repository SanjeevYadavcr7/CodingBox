class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size(), m;
        vector<int> keyArr;
        vector<int> ans;
        
        for(int j=0; j<n; j++){
            if(nums[j] == key) keyArr.push_back(j);
        }
        m = keyArr.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(abs(i-keyArr[j]) <= k){
                    ans.push_back(i);
                    break;
                }    
            }
        }
        return ans;
    }
};
