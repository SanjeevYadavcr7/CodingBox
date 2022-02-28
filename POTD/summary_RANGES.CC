#include<bits/stdc++.h>
using namespace std;

vector<string> summaryRanges(vector<int>& nums){
	int n = nums.size();
	vector<string> ranges;
	string range = "";
	range += nums[0];
	
	for(int i = 1; i < n; i++){
		if(nums[i] == nums[i-1]+1) range += (""+nums[i]);
		else{
			int range_size = range.size();
			if(range_size == 1) ranges.push_back(range);
			else{
				string str = range[0] + "->" + range[range_size-1];
				ranges.push_back(str);
			}
			range = ""+nums[i];
		}
	}
	return range;
}

int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];
	
	vector<string> ranges = summaryRanges(nums);
	for(string range : ranges) cout << range << " ";
	cout << "\n";

	return 0;
}
