#include<bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h){
	
}

int main(){
	int n, h;
	cin >> n;
	vector<int> piles(n);
	for(int i=0; i<n; i++) cin >> piles[i];
	cin >> h;

	int eating_spped = minEatingSpeed(piles,h);
	cout << eating_speed << "\n";


	return 0;
}
