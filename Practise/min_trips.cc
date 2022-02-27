#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int getTrips(ll t,vector<int>& time){
	int trip = 0;
	for(int& i : time) trip += (t/i);
	return trip;
}

long long minimumTime(vector<int>& time, int totalTrips){	
	int max_time = INT_MIN;
	for(int& i : time) max_time = max(max_time,i);
	
	ll l = 0, r = max_time*totalTrips, ans = 0;	
	
	while(l <= r){
		ll m = l+(r-l)/2;
		int trips = getTrips(m,time);
		if(trips >= totalTrips){
			r = m-1;
			ans = m;
		}
		else l = m+1;
	}
	return ans;
}

int main(){
	int n,total;
	cin >> n;
	vector<int> time(n);
	for(int i=0; i<n; i++) cin >> time[i];
	cin >> total;
	
	long long min_time = minimumTime(time,total);
	cout << min_time << "\n";
	
	return 0;
}
