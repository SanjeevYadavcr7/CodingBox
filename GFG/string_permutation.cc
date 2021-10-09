#include<bits/stdc++.h>
using namespace std;

void display(vector<string> arr){
	int n = arr.size();
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int fact(int n){
	if(n == 1) return 1;
    return n * fact(n-1);
}

string generatePermutedString(int num, string S, int n){
	string ans = "";
	while(n > 0){
		int index = num % n;
		num /= n;
		ans += S[index];
		S.erase(index,1);
		n -= 1;
	}
	return ans;
}
    
vector<string> permutation(string S){
	vector<string> ans;
	int n = S.length();
	int n_sub = fact(n);
	
	for(int i=0;i<n_sub;i++){
		int num = i;
		string str = generatePermutedString(i,S,n);
		ans.push_back(str);
	}
	sort(ans.begin(), ans.end());
	return ans;
}


int main(){
	string str;
	cin>>str;
	vector<string> arr = permutation(str);
	display(arr);
	return 0;
}
