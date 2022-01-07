#include<bits/stdc++.h>
using namespace std;

int getpaintingWays(int n, int k){
	int same = k, diff = k*(k-1), total;
	for(int i=2;i<=n;i++){
		int temp = diff;
		total = same+diff;
		diff = total * (k-1);
		same = temp;
	}
	return total;
}

int main(){
	int n, k;
	cin>> n >> k;
	
	int painting_ways = getpaintingWays(n,k);
	cout<<painting_ways<<"\n";
	
	return 0;
}
