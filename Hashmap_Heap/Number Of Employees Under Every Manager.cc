#include<bits/stdc++.h>
using namespace std;

int getSize(char mg, unordered_map<char, vector<char>> mp, map<char,int>& res) {
	if(mp.find(mg) == mp.end()){
		res[mg] = 0;
		return 1;
	}
	
	int size = 0;
	for(char emp : mp[mg]) {
		size += getSize(emp,mp,res);
	}
	res[mg] = size;
	return size+1;
}

map<char,int> getEmployeeMapping(vector<vector<char>>& arr) {
	char ceo;
	map<char,int> res;
	unordered_map<char, vector<char>> mp;
	
	for(auto i : arr) {
		char emp = i[0], mg = i[1];
		if(emp == mg) ceo = emp;
		else mp[mg].push_back(emp);
	}		
	getSize(ceo,mp,res);
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<vector<char>> arr(n,vector<char>(2));
	for(int i=0; i<n; i++)
		for(int j=0; j<2; j++) cin >> arr[i][j];
	
	map<char,int> res = getEmployeeMapping(arr);
	for(auto i : res) cout << i.first << " -> " << i.second << endl; 

	return 0;
}
