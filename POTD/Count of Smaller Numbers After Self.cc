#include<bits/stdc++.h>
using namespace std;
void display(vector<int>& arr){for(int& i : arr) cout << i << " "; cout << "\n";}

// Approach: Divide and Conquer | TC: O(NlogN) | SC: O(N)

void merge(int l, int m, int r, vector<pair<int,int>>& nums, vector<int>& count){
	int i = l, j = m+1;
	vector<pair<int,int>> temp;
	
	while(i<=m && j<=r){ 
		if(nums[i].first <= nums[j].first) temp.push_back(nums[j++]);
		else{
			count[nums[i].second] += (r-j+1);
			temp.push_back(nums[i++]);		
		}
	}
	
	while(i<=m) temp.push_back(nums[i++]);
	while(j<=r) temp.push_back(nums[j++]);
	
	for(int k=l; k<=r; k++){
		nums[k] = temp[k-l];
	}
}

void mergeSort(int l, int r, vector<pair<int,int>>& nums, vector<int>& count){
	if(l<r){
		int mid = (r-l)/2+l;
		mergeSort(l,mid,nums,count);
		mergeSort(mid+1,r,nums,count);
		merge(l,mid,r,nums,count);
	}
}

vector<int> countSmaller(vector<int>& nums){
	int n = nums.size();
	vector<int> count(n);
	vector<pair<int,int>> temp(n);
	
	for(int i=0; i<n; i++) temp[i] = {nums[i],i};
	mergeSort(0,n-1,temp,count);
	return count;
}

/*
int getSmallerCount(int beg, int end, vector<int>& nums, unordered_map<int,int>& freq){
	if(beg>end) return 0;
	
	int cnt = 0;
	int mid = (end-beg)/2+beg;
	cnt = freq[mid] + getSmallerCount(beg,mid-1,nums,freq) + getSmallerCount(mid+1,end,nums,freq);
	return cnt;
}

vector<int> countSmaller(vector<int>& nums){
	int n = nums.size();
	int beg; 
	unordered_map<int,int> freq;
	vector<int> count;
	
	for(int& i : nums) freq[i]++;
	
	beg = *min_element(nums.begin(),nums.end());
	for(int& curr : nums){
		int smaller_count = getSmallerCount(beg,curr-1,nums,freq);
		count.push_back(smaller_count);
		freq[curr]--;
	}
	return count;
}
*/


int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];

	vector<int> res = countSmaller(nums);
	display(res);

	return 0;
}
