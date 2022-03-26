class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int beg = 0, end = n-1;
        while(beg <= end){
            int mid = (end-beg)/2+beg;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) beg = mid+1;
            else end = mid-1;
        }
        return -1;
    }
};
