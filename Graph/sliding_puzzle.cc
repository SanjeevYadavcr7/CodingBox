#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;

bool isOutofBoundary(int i, int j, int n, int m){
	if(i < 0 || i == n || j < 0 || j == m) return true;
    return false;
}

string swapChars(string str, int idx, int i){
	string new_str = "";
	for(int j=0; j<6; j++){
		if(j == idx) new_str += str[i];
		else if(j == i) new_str += str[idx];
		else new_str += str[j];
	}
	return new_str;
}

int slidingPuzzle(vector<vector<int>>& board){
	int n = board.size(), m = board[0].size();
	vector<vector<int>> pos_swaps ={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{4,2}};
	string tar = "123450", init = "";
	queue<string> Q;
	unordered_map<string,bool> vis;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) init += to_string(board[i][j]); 
	} 	   
	
	int moves = 0;
	Q.push(init);

	while(!Q.empty()){
		int s = Q.size();
		while(s--){
			string str = Q.front();
			Q.pop();
			if(str == tar) return moves;
			
			int idx = -1;
			for(int i=0; i<str.length(); i++){
				if(str[i] == '0'){
					idx = i;
					break;
				}
			}
			
			for(int i=0; i<pos_swaps[idx].size(); i++){
				string new_str = swapChars(str,idx,pos_swaps[idx][i]);
				if(vis[new_str]) continue;
				Q.push(new_str);
				vis[new_str] = true;
			}
		}
		moves++;
	}
	return -1;
}

int main(){
    vector<vector<int>> v1(2,vector<int>(3));
    for(int i=0;i<2;++i) 
        for(int j=0;j<3;++j) cin>>v1[i][j];
    int ans=slidingPuzzle(v1);
    cout<<ans<<"\n";
    return 0;
}
