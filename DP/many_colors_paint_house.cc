#include<bits/stdc++.h>
using namespace std;

int minPaintCost(vector<vector<int>> cost,int n, int k){
	for(int i=1;i<n;i++){
		vector<int> temp_cost;
		for(int j=0;j<k;j++){
			int min_cost = INT_MAX;
			
			for(int l=0;l<k;l++) if(l != j) min_cost = min(min_cost,cost[i-1][l]);
			
			min_cost += cost[i][j];
			temp_cost.push_back(min_cost);
		}
		for(int j=0;j<k;j++) cost[i][j] = temp_cost[j];	
	}
	
	int min_cost = INT_MAX;
	for(int i=0;i<k;i++) min_cost = min(min_cost,cost[n-1][i]);	
	return min_cost;
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<vector<int>> cost;
	for(int i=0;i<n;i++){
		vector<int> temp_cost;
		for(int i=0;i<k;i++){
			int x;
			cin>>x;
			temp_cost.push_back(x);
		}
		cost.push_back(temp_cost);
	}

	int min_cost = minPaintCost(cost,n,k);
	cout<<min_cost<<"\n";
	
	return 0;
}
