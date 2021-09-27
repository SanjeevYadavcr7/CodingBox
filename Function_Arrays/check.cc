#include<iostream>
using namespace std;

void solve(int n, int m){
	int x = n%m;
	cout<<x<<endl;
}

int main(){
	int n,m;
	cin>>n>>m;
	solve(n,m);
	return 0;
}
