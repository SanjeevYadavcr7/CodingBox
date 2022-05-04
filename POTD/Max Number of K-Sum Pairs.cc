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
	vector<int> nums = {73,74,74,71,68,67,45,1,24,2,26,48,82,82,28,60,19,36,26,9,12,83,1,86,18,78,14,66,20,26,4,80,44,35,53,48,74,25,75,47,31,20,59,10,35,24,26,3,48,69,78,43,12,86,37,49,1,90,20,35,58,20,2,20,16,18,88,25,44,63,12,16,64,41,86,87,2,23,14,63,43,60,47,7,23,11,64,53,71,78,82,56,65,25,27,52,89,68,63,14,48};
	
	//for(int i=0; i<n; i++) cin >> nums[i];
	
	int op = maxOperations(nums,k);
	cout << op << endl;
	 
	return 0;
}


/*
{73,74,74,71,68,67,45,1,24,2,26,48,82,82,28,60,19,36,26,9,12,83,1,86,18,78,14,66,20,26,4,80,44,35,53,48,74,25,75,47,31,20,59,10,35,24,26,3,48,69,78,43,12,86,37,49,1,90,20,35,58,20,2,20,16,18,88,25,44,63,12,16,64,41,86,87,2,23,14,63,43,60,47,7,23,11,64,53,71,78,82,56,65,25,27,52,89,68,63,14,48}
44

arr = [4 4 1 3 1 3 2 2 5 5 1 5 2 1 2 3 5 4] | k = 2
	  
	  4 --> 3
	  1 --> 4
	  3 --> 3
	  2 --> 4
	  5 --> 4

	  	

*/
