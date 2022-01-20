#include<bits/stdc++.h>
using namespace std;

int isPossibleToEat(vector<int>& piles, int sp, int h){
	int time = 0;
	for(int i=0; i<piles.size(); i++) time += ceil(piles[i]/sp);
	return (time <= h);
}

int minEatingSpeed(vector<int>& piles, int h){
	    int low = 1, high = INT_MIN;
        
        for(auto x : piles) high = max(x,high);
        
        int val = 0;
        while(low < high){
            int mid = low + (high - low)/2; val = 0;
            for (auto x : piles) val += (x+mid-1)/mid; 
            if (val <= h) high = mid; 
            
            else low = mid+1; 
        }
        return low;
}

int main(){
	int n, h;
	cin >> n;
	vector<int> piles(n);
	for(int i=0; i<n; i++) cin >> piles[i];
	cin >> h;

	int eating_speed = minEatingSpeed(piles,h);
	cout << eating_speed << "\n";


	return 0;
}
