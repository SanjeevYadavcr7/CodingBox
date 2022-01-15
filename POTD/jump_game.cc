#include<bits/stdc++.h>
using namespace std;

int minJumps(vector<int>& arr){	
	int n = arr.size(), steps = 0;
	vector<bool> vis(n);
	map<int,vector<int>> mp;
	for(int i=0;i<n;i++) mp[arr[i]].push_back(i);
	
	queue<int> q;
	q.push(0);
	vis[0] = true;
	while(!q.empty()){
		steps++;
		int q_size = q.size();
		while(q_size--){
			int j = q.front();
			q.pop();
			if(j+2 == n) return steps;
			if(j-1 >= 0 && !vis[j-1]){
				vis[j-1] = true;
				q.push(j-1);
			} 
			if(j+1 < n && !vis[j+1]){
				vis[j+1] = true;
				q.push(j+1);
			} 
			
			if(mp[arr[j]].size() == 0) continue;
			for(int k:mp[arr[j]]){
				if(!vis[k]) q.push(k);
				if(k == n-1) return steps;
			}
			mp.erase(arr[j]);
		}
	}
	return steps;
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






















































/*
int min_jumps = INT_MAX;
void jumpingStairs(int curr,int stop, vector<int>& arr, int jumps, vector<bool>& vis, map<int,vector<int>>& mp){
        if(curr < 0 || curr > stop || vis[curr]) return;
        if(curr == stop){
            min_jumps = min(min_jumps,jumps);
            return;
        }
        vis[curr] = true;
        for(int i:mp[arr[curr]]) jumpingStairs(i,stop,arr,jumps+1,vis,mp);
        /*
        for(int i=stop;i>curr;i--){
            if(arr[curr] == arr[i]){
                jumpingStairs(i,stop,arr,jumps+1,vis);
            } 
        }
        */
        /*
        jumpingStairs(curr+1,stop,arr,jumps+1,vis,mp);
        jumpingStairs(curr-1,stop,arr,jumps+1,vis,mp);
        vis[curr] = false;
}
/*
int minJumps(vector<int>& arr){	
        int start = 0, stop = arr.size()-1;
        vector<bool> vis(stop+1,false);

        map<int,vector<int>> mp;
        for(int i=0;i<=stop;i++) mp[arr[i]].push_back(i);
        
        jumpingStairs(start,stop,arr,0,vis, mp);
        return min_jumps;
}
*/
