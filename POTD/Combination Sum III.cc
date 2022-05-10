#include "utils.h"

// TC: O(K*C(N,K)) | SC: O(K)

vector<vector<int>> res;
void getCombination(int num, int curr_sum, int k, int tar, vector<int> temp) {
	 if(num > tar || curr_sum > tar || temp.size() > k) return;
        
     if(curr_sum == tar && temp.size() == k) {
     	res.push_back(temp);
        return;
     }
     
     for(int i=num+1; i<=tar && i<=9; i++) {
     	temp.push_back(i);
     	getCombination(i,curr_sum+i,k,tar,temp);
     	temp.pop_back();
     }   
}

vector<vector<int>> combinationSum3(int k, int n) { 
	vector<int> temp;
	getCombination(0,0,k,n,temp);
	return res;
}

/*  Approach: Pick and Non-pick | Type: Sub-optimal | TC: O(2^N*K) | SC: O(N)

vector<vector<int>> res;
void getCombination(int num, int curr_sum, int tar, int k, vector<int> temp) {
        if(num > tar || curr_sum > tar || temp.size() > k) return;
        
        if(curr_sum == tar && temp.size() == k) {
            res.push_back(temp);
            return;
        }
        
        getCombination(num+1,curr_sum,tar,k,temp);
        temp.push_back(num);
        getCombination(num+1,curr_sum+num,tar,k,temp);
        temp.pop_back();
}
    
vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        getCombination(1,0,n,k,temp);
        return res;
}

*/

int main() {
	int k,n;
	cin >> k >> n;
	
	vector<vector<int>> res = combinationSum3(k,n);
	display(res);

	return 0;
}
