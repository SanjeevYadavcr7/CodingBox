#include<bits/stdc++.h>
using namespace std;

int min_jumps = INT_MAX;

void jumpingStairs(int curr,int stop, vector<int>& arr, int jumps, vector<bool>& vis){
        if(curr < 0 || curr > stop || vis[curr]) return;
        if(curr == stop){
            min_jumps = min(min_jumps,jumps);
            return;
        }
        vis[curr] = true;
        for(int i=stop;i>curr;i--){
            if(arr[curr] == arr[i]){
                jumpingStairs(i,stop,arr,jumps+1,vis);
            } 
        }
        jumpingStairs(curr+1,stop,arr,jumps+1,vis);
        jumpingStairs(curr-1,stop,arr,jumps+1,vis);
        vis[curr] = false;
}

int minJumps(vector<int>& arr){	
        int start = 0, stop = arr.size()-1;
        vector<bool> vis(stop+1,false);
        jumpingStairs(start,stop,arr,0,vis);
        return min_jumps;
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin >> arr[i];

	int jumps = minJumps(arr);
	cout << jumps << "\n";

	return 0;
}
