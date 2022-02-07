#include<bits/stdc++.h>
using namespace std;

int numBusesToDestination(vector<vector<int>>& stops, int source, int target) {
	int n = stops.size();
	unordered_map<int,vector<int>> stop_busno_map;
	for(int i=0; i<n; i++){
		for(int j=0; j<stops[i].size(); j++){
			int curr_stop = stops[i][j];
			stop_busno_map[curr_stop].push_back(i);
		} 
	}	

	int buses = 0;
	vector<bool> vis_bus(n,false);
	unordered_map<int,bool> stop_vis;	
	queue<int> Q;		
	
	Q.push(source);
	stop_vis[source] = true;	
	
	while(!Q.empty()){
		int size = Q.size();
		while(size--){
			auto curr_stop = Q.front();
			Q.pop();
			if(curr_stop == target) return buses;
			
			for(int bus : stop_busno_map[curr_stop]){
				if(vis_bus[bus]) continue;
				for(auto stop : stops[bus]){
					if(stop_vis[stop]) continue;
					Q.push(stop);
					stop_vis[stop] = true;
				}
				vis_bus[bus] = true;
			}
		}
		buses++;
	}
	return -1;
}

int main(){
	int n,m;
	cin >> n;
	vector<vector<int>> routes;
	for(int i=0; i<n; i++){
		cin >> m;
		vector<int> stops(m,0);
		for(int j=0; j<m; j++) cin >> stops[j];
		routes.push_back(stops);
	}
	
	int s,d;
	cin >> s >> d;
	
	int min_buses = numBusesToDestination(routes,s,d);
	cout << min_buses << "\n";

	return 0;
}
