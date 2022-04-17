#include<bits/stdc++.h>
using namespace std;

int twoCitySchedCost(vector<vector<int>>& costs){
	int n = costs.size(), min_cost = 0, limit = n/2, a = 0;
	priority_queue<pair<int,int>> Q;
	
	for(int i=0; i<n; i++){
		int a_cost = costs[i][0];
		int b_cost = costs[i][1];
		int profit = b_cost - a_cost;
		Q.push({profit,i});
	}
	
	while(!Q.empty()){
		auto curr = Q.top();
		Q.pop();
		
		int cost = curr.first;
		int idx = curr.second;
		if(a < limit){
			min_cost += costs[idx][0];
			a++;
		}
		else min_cost += costs[idx][1];
	}
	return min_cost;
}

/*
static bool sortCol(vector<int>& a,vector<int>& b){
  return ( abs(a[0]-a[1]) > abs(b[0] - b[1]) );
}

int twoCitySchedCost(vector<vector<int>>& costs){
  sort(costs.begin(), costs.end(),sortCol);
  
  int totalCities = costs.size();
  int cityA = totalCities/2;
  int cityB = cityA;
  int minCost = 0;
  for(int i=0;i<totalCities;i++){
    int cityAcost = costs[i][0];
    int cityBcost = costs[i][1];
    if(cityB == 0 || (cityA>0 && cityAcost <= cityBcost)){
      cityA--;
      minCost += cityAcost;
    }
    else{
      cityB--;
      minCost += cityBcost;
    }
  }
  return minCost;
}
*/


int main(){
	int n,a,b;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(2));
	for(int i=0; i<n; i++) cin >> arr[i][0] >> arr[i][1];
	
	int cost = twoCitySchedCost(arr);
	cout << cost << "\n";

	return 0;
}
