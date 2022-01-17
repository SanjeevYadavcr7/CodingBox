#include<bits/stdc++.h>
using namespace std;

/*
int maxDistToClosest(vector<int>& seats){
	int n = seats.size();
	vector<int> left(n), right(n);
	
	int nei = 0;
	left[0] = INT_MAX;
	for(int i=1; i<n; i++){		
		if(seats[i]){
			left[i] = INT_MAX;
			nei = i;
		} 
		else left[i] = i-nei;
	}
	
	right[n-1] = INT_MAX;
	nei = n-1;
	for(int i=n-2;i>=0;i--){
		if(seats[i]){
			right[i] = INT_MAX;
			nei = i;
		}			
		else right[i] = nei - i;
	}	
	int ans = INT_MIN;
	for(int i=0; i<n; i++){
		seats[i] = min(left[i],right[i]);
		if(seats[i] != INT_MAX) ans = max(ans,seats[i]);
	} 
	
	return ans;
}
*/

int maxDistToClosest(vector<int>& seats) {
      int n = seats.size(), l = -1, max_dis = 0;
      for(int i=0; i<n; i++){
      	if(seats[i]){
      		if(l == -1) max_dis = i;
      		else max_dis = max(max_dis, (i-l)/2);
      		l = i;
      	}
      }
      
      if(!seats[n-1]) max_dis = max(max_dis, n-1-l);
      return max_dis;
}

int main(){
	int n;
	cin >> n;
	vector<int> seats(n);
	for(int i=0; i<n; i++) cin >> seats[i];

	int max_dis = maxDistToClosest(seats);
	cout << max_dis << "\n";
	
	return 0;
}
