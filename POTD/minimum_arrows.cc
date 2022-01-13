#include<bits/stdc++.h>
using namespace std;

bool customCompare(vector<int> a, vector<int> b){
	if(a[0] == b[0]) return a[1] < b[1];
	return a[0] < b[0];
}

bool isOverlapping(int x_start, int x_end, int curr_x_start, int curr_x_end){
	if((x_start <= curr_x_start && x_end >= curr_x_start) || (x_start <= curr_x_end && x_end >= curr_x_end)) return true;
	return false;
}

int findMinArrowShots(vector<vector<int>>& points){
	sort(points.begin(),points.end(),customCompare);
	
	stack<vector<int>> stk;
	for(vector<int> point : points){
		if(stk.empty()) stk.push(point);
		else{
			vector<int> temp = stk.top();
			int x_start = temp[0], x_end = temp[1];
			int curr_x_start = point[0], curr_x_end = point[1];
			if(isOverlapping(x_start, x_end, curr_x_start, curr_x_end)){
				x_start = max(x_start,curr_x_start);
				x_end = min(x_end,curr_x_end);
				vector<int> new_point = {x_start, x_end};
				stk.pop();
				stk.push(new_point);
			}
			else{
				vector<int> new_point = {curr_x_start, curr_x_end};
				stk.push(new_point);
			}
		}
	}
	
	return stk.size();	
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> points;
	for(int i=0;i<n;i++){
		int x_start, x_end;
		vector<int> temp;
		cin >> x_start >> x_end; 
		temp.push_back(x_start);
		temp.push_back(x_end);
		points.push_back(temp);	
	}
	
	int min_arrows = findMinArrowShots(points);
	cout << min_arrows << "\n";
	
	return 0;
}
