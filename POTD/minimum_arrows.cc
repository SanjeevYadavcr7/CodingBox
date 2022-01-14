#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {return a[1] < b[1];}

int findMinArrowShots(vector<vector<int>>& segments) {
	sort(segments.begin(), segments.end(), cmp);
    
    cout<<"\n";
    for(vector<int> v:segments){
    	for(int i:v) cout<<i<<" ";
    	cout<<"\n";
    }
    cout<<"\n";
    
    int ans = 0, arrow = 0;
    for (int i = 0; i < segments.size(); i ++) {
    	if (ans == 0 || segments[i][0] > arrow) {
        	ans ++;
            arrow = segments[i][1];
        }
    }
    return ans;
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
