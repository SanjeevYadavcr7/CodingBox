#include<bits/stdc++.h>
using namespace std;

int maxOperations(vector<int>& nums, int k) {
	int op = 0;
    map<int,int> freq;

    for(int& i : nums) freq[i] += 1;

    for(auto i : freq) {
    	int num = i.first;
        int req_num = k - num;
        int num_freq = i.second;
        freq[num] -= 1;

        if(req_num < 0) continue;
        if(req_num*2 == k) {
        	op += num_freq/2;
            freq[req_num] = num_freq % 2;
         }
         else if(freq[req_num] > 0) {
         	if(freq[req_num] == num_freq) {
             	op += num_freq;
                freq[num] = freq[req_num] = 0;
            }
            else {
            	int min_freq = min(num_freq,freq[req_num]);
                op += min_freq;
                freq[num] = freq[req_num] = 0;
            }
        }
    }
    return op;
}
    

int main() {
	int n,k;
	cin >> n >> k;
	vector<int> nums(n);
	for(int i=0; i<n; i++) cin >> nums[i];
	
	int op = maxOperations(nums,k);
	cout << op << endl;
	 
	return 0;
}
