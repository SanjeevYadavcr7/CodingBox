#include<bits/stdc++.h>
using namespace std;

vector<string> summaryRanges(vector<int>& nums){
	int n = nums.size();
	vector<string> ranges;
	
	for(int i=0; i<n; i++){
		int beg = nums[i];
		while(i+1 < n && nums[i]+1 == nums[i+1]) i++;
		if(beg != nums[i]){
			ranges.push_back(""+to_string(beg)+"->"+to_string(nums[i]));
		}
		else ranges.push_back(""+to_string(beg));
	}
	return ranges;
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
