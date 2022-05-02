#include<vector>
#include<iostream>
using namespace std;

vector<int> duplicates(int nums[], int n) {
        vector<int> res;
        
        for(int i=0; i<n; i++) nums[nums[i]%n] = nums[nums[i]%n] + n; 
        for(int i=0; i<n; i++) {
            if(nums[i] >= n*2) res.push_back(i);
        }
        
        if(res.size() == 0) res.push_back(-1);
        
        return res;
}

int main() {
	int n;
	cin >> n;
	int nums[n];
	for(int i=0; i<n; i++) cin >> nums[i];
	
	vector<int> res = duplicates(nums,n);
	for(int i : res) cout << i << " ";
	cout << endl;
	
	return 0;
}
