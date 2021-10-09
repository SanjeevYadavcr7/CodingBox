#include<bits/stdc++.h>
using namespace std;

void display(vector<string> arr){
	int n = arr.size();
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

vector<string> mp{{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}};
int x = 0;

vector<string> possibleWords(int a[], int N)
{	
	if(N == 0){
		vector<string> ans{{""}};
		return ans;
	}
	string o_str = mp[a[x]];
	x += 1;
	vector<string> temp = possibleWords(a,N-1);
	vector<string> ans;
	
	for(char i : o_str){
		for(string j : temp){
			string str = "";
			str += i;
			str += j;
			ans.push_back(str);
		}
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	vector<string> ans = possibleWords(arr, n);
	display(ans);
	return 0;
}
