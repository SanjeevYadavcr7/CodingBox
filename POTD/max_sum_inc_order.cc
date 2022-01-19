#include<bits/stdc++.h>
using namespace std;

void displayData(vector<vector<int>> &arr);
void insertData(int n, int m, vector<vector<int>> &arr);

void msHelper(int cs, int &ms, int pm, int i, int m, vector<vector<int>> &a){ 
	if(i < 0){ 
		ms = max(ms,cs);
		return;
	}
	int max_num = INT_MIN;
	for(int j=0; j<m; j++){
		if(max_num < a[i][j] && a[i][j] < pm) max_num = a[i][j];
	}
	if(max_num != INT_MIN) msHelper(cs+max_num,ms,max_num,i-1,m,a);
}

int maximumSum( int n,int m, vector<vector<int>> &a) {
	int cs = 0, ms = 0, pm = INT_MAX;
	msHelper(cs,ms,pm,n-1,m,a);
	return ms;
}


int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr;
	insertData(n,m,arr);
	
	int max_sum = maximumSum(n,m,arr);
	cout << max_sum << "\n";
	
	return 0;
}




































void displayData(vector<vector<int>> &arr){
	cout<<"\n";
	for(auto i:arr){
		for(int j:i) cout << j << " ";
		cout << "\n";
	}
}



void insertData(int n, int m, vector<vector<int>> &arr){
	for(int i=0; i<n; i++){
		vector<int> temp;
		for(int j=0; j<m; j++){
			int val;
			cin >> val;
			temp.push_back(val);
		}
		arr.push_back(temp);
	}
}
