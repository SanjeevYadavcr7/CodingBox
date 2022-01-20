#include<bits/stdc++.h>
using namespace std;

void printLexPattern(int i, int n, vector<bool>& vis){
	if(i > n || vis[i]) return;
	
	vis[i] = true;
	cout << i << "\n";
	printLexPattern(i*10,n,vis);
	printLexPattern(i+1,n,vis);
}

void printLexPattern(int i, int n){
	if(i > n) return;
	cout << i << "\n";
	for(int j=0; j<=9; j++){
		printLexPattern(10*i+j,n);
	}
}	

int main(){
	int n;
	cin >> n;
	
	/*
	int beg = 1;
	vector<bool> vis(n+1,false);
	printLexPattern(beg,n,vis);	
	*/
	for(int i=1; i<=9; i++) printLexPattern(i,n);
	
	return 0;
}
