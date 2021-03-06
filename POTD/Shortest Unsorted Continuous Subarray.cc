#include<bits/stdc++.h>
using namespace std;

// Idea is same as below appraoch but uses a single loop (*Leetcode discuss solution)

namespace x {
	int max = INT_MIN, min = INT_MAX;
}

int findUnsortedSubarray(vector<int>& nums) {
	int n = nums.size();
	int beg = -1, end = -1;
	int left = 0, right = n-1;
	
	while(right >= 0) {
		if(nums[left] < x::max) end = left;
		else x::max = nums[left];
		
		if(nums[right] > x::min) beg = right;
		else x::min = nums[right];
		
		left++;
		right--; 
	}
	return beg != -1 ? end-beg+1 : 0;
}


/*---------------------------------------------------------------*/

class Solution {
public:
    int placeMinNum(vector<int>& nums, int min_num) {
        int i=0;
        while(nums[i] <= min_num) i++;
        return i;
    }
    
    int placeMaxNum(vector<int>& nums, int max_num) {
        int n = nums.size();
        int i = n-1;
        while(nums[i] >= max_num) i--;
        return i;
    }
    
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        bool is_unsorted = false;
        int idx;
        
        for(int i=0; i<n-1; i++) {
            if(nums[i] > nums[i+1]) {
                idx = i;
                is_unsorted = 0;
                break;
            }   
        }
        
        if(!is_unsorted) return 0;
        
        int min_num = INT_MAX;
        for(int i=idx; i<n; i++) min_num = min(min_num,nums[i]);
        int l = placeMinNum(nums,min_num);
        
        for(int i=n-1; i>0; i--) {
            if(nums[i] < nums[i-1]) {
                idx = i;
                break;
            }    
        }
        
        int max_num = INT_MIN;
        for(int i=idx; i>=0; i--) max_num = max(max_num,nums[i]);
        int r = placeMaxNum(nums,max_num);
        return r-l+1;
    }
};

int main() {
	int n;
	std::cin >> n;
	std::vector<int> nums(n);
	for(int i=0; i<n; i++) std::cin >> nums[i];
	
	Solution obj;
	std::cout << findUnsortedSubarray(nums) << std::endl;
	
	return 0;	
}
