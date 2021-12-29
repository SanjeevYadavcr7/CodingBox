#include <bits/stdc++.h>
using namespace std;

int climb_stairs(int n, map<int,int>& ways){
	if(n<0) return 0;
	if(n == 0) return 1;
	
	if(ways[n] != 0) return ways[n];
	
	int waysByN = climb_stairs(n-1,ways) + climb_stairs(n-2,ways) + climb_stairs(n-3,ways);
	ways[n] = waysByN;
	return waysByN;
}

int climb_stairs_tab(int n){
	vector<int> ways(n+1,0);
	ways[0] = 1;
	for(int i=1;i<=n;i++){
		ways[i] = ways[i-1] + ((i>1) ? ways[i-2] : 0) + ((i>2) ? ways[i-3] : 0);
	}
	return ways[n];
}

int cs(int n){
	map<int,int> ways;
	int total_ways = climb_stairs_tab(n);
	return total_ways;
}

int main(){
    int n;
    cin>>n;
    cout<<cs(n)<<endl;
}
