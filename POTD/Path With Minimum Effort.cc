#include<bits/stdc++.h>
using namespace std;

/* Aproach: Dijkstra(Greedy) | TC: O(M*N Log(M*N)) | SC: O(M*N)

int m,n;
bool outOfBox(int row, int col){
	if(row<0 || col<0 || row>=m || col>=n) return true;
	return false;
}

int minimumEffortPath(vector<vector<int>>& heights) {
	m = heights.size(), n = heights[0].size();
	vector<vector<int>> minEffort(m,vector<int>(n,INT_MAX));
	vector<vector<int>> dirs = {{0,-1}, {-1,0}, {0,1}, {1,0}};
	priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;  // to strore min effors
	
	minEffort[0][0] = 0;
	minHeap.push({0,0,0});   // {effort, row, col}
	while(!minHeap.empty()){
		auto cell = minHeap.top();
		minHeap.pop();
		
		int effort = cell[0], x = cell[1], y = cell[2];
		
		if(x == m-1 && y == n-1) return effort;
		
		for(auto dir : dirs){
			int new_x = x + dir[0];
			int new_y = y + dir[1];
			if(outOfBox(new_x,new_y)) continue;
			int effort_till_now = max(effort,abs(heights[x][y]-heights[new_x][new_y]));
			if(effort_till_now < minEffort[new_x][new_y]){
				minEffort[new_x][new_y] = effort_till_now;
				minHeap.push({effort_till_now,new_x,new_y});
			}
		}
	}
	return 0;
}
*/

int main(){
	int m,n;
	cin >> m >> n;
	vector<vector<int>> heights(m,vector<int>(n));
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++) cin >> heights[i][j];
	
	int effort = minimumEffortPath(heights);
	cout << effort << endl;
	return 0;
}
