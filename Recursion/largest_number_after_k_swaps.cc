#include<bits/stdc++.h>
using namespace std;

string swap(int idx, int max_idx, string num){
	string temp = num;
	char ch = temp[idx];
	temp[idx] = temp[max_idx];
	temp[max_idx] = ch;
	return temp;
}

void maxPossibleNum(int idx, string num, int k, string& ans){
	if(k == 0 || idx == num.size()){
		if(num > ans) ans = num;
		return;
	} 
	
	if(num > ans) ans = num;
	
	int max_num = INT_MIN;
	for(int i=idx; i<num.size(); i++){
		int curr = num[i] - '0';
		max_num = max(max_num,curr);
	}
	
	for(int i=idx; i<num.size(); i++){
		int curr = num[i] - '0';
		if(curr == max_num){
			if(idx == i) maxPossibleNum(idx+1,num,k,ans);
			else{
				num = swap(i,idx,num);
				maxPossibleNum(idx+1,num,k-1,ans);
				num = swap(i,idx,num);
			}
		} 	 
	}
}

int main(){
	int k;
	string num;
	cin >> num;
	cin >> k;
	string max_num = "0";
	unordered_map<int,bool> mp;
	maxPossibleNum(0,num,k,max_num);
	cout << max_num << "\n";

	return 0;
}
































