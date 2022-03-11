#include<bits/stdc++.h>
using namespace std;

struct customPair{
	int idx;
	int len;
	vector<int> seq;
	customPair(int idx, int len, vector<int> seq){
		this->idx = idx;
		this->len = len;
		this->seq = seq;
	}
};

void display(vector<int>& temp);

void printAllLIS(int len, vector<int>& nums, int dp[]){
	int n = nums.size();
	queue<customPair*> Q;
	
	for(int i=0; i<n; i++){
		if(dp[i] == len){
			vector<int> seq = {nums[i]};
			customPair* temp = new customPair(i,len,seq);
			Q.push(temp);
		}
	}
	
	while(!Q.empty()){
		int size = Q.size();
		while(size--){
			customPair* it = Q.front();
			int idx = it->idx;
			int len = it->len;
			vector<int> seq = it->seq;
			Q.pop();
			
			if(len == 1){
				display(seq);
				continue;
			}
			
			int max_len = len-1;
			//for(int j=idx-1; j>=0; j--) max_len = max(max_len,dp[j]);
			for(int j=idx-1; j>=0; j--){
				if(dp[j] == max_len){
					vector<int> new_seq = seq;
					new_seq.push_back(nums[j]);
					customPair* new_pair = new customPair(j,dp[j],new_seq);
					Q.push(new_pair);
				}
			}
		}
	}
}

void longestIncreasingSubseq(vector<int>& nums){
	int n = nums.size();
  
         int list[n];
         list[0]=1;
        
         for(int i=1; i<n; i++){
             list[i]=1;
             for(int j=0; j<i; j++){
                 if(nums[i] > nums[j] and list[i]<=list[j] ){
                     list[i]=list[j]+1;
                 }
             }
        }
    
    int len = *max_element(list,list+n);
		
	printAllLIS(len,nums,list);    
}

int main(){	
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	longestIncreasingSubseq(arr);

	return 0;
}































void display(vector<int>& temp){
	int n = temp.size();
	for(int i=n-1; i>=0; i--){
		cout << temp[i];
		if(i != 0) cout << " -> ";
		else cout << " .\n";
	}
}
