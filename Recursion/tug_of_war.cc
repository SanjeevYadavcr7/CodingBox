#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>> arr);

int min_diff = INT_MAX;
vector<vector<int>> ans;

int compareTeams(vector<vector<int>>& teams){
	vector<int> power(2,0);
	for(int i=0; i<teams.size(); i++){
		for(int j=0; j<teams[i].size(); j++) power[i] += teams[i][j];
	}
	int power_diff = abs(power[0] - power[1]);
	return power_diff;
}

void playTugOfWar(int idx, vector<int>& players, vector<vector<int>>& teams){
	if(idx == players.size()){
		int power_diff = compareTeams(teams);
		int player_diff = abs((int)teams[0].size() - (int)teams[1].size());
		if(min_diff > power_diff && player_diff <=1){
			min_diff = power_diff;
			ans = teams;
		}
		/*
		min_diff = min(min_diff,power_diff);
		if(min_diff == power_diff) ans = teams;
		*/
		return;
	}
	
	for(int i=0; i<teams.size(); i++){
		if(teams[i].size() > 0){
			teams[i].push_back(players[idx]);
			playTugOfWar(idx+1,players,teams);
			teams[i].pop_back();
		}
		else{
			teams[i].push_back(players[idx]);
			playTugOfWar(idx+1,players,teams);
			teams[i].pop_back();
			break;
		}
	}
}

vector<vector<int>> tugOfWar(vector<int>& players, int k){
	vector<vector<int>> teams(k);
	playTugOfWar(0,players,teams);
	return ans;
}

int main(){
	int n;
	cin >> n;
	vector<int> players(n);
	for(int i=0; i<n; i++) cin >> players[i];
	
	vector<vector<int>> teams = tugOfWar(players,2);
	display(teams);
	
	return 0;
}







































void display(vector<vector<int>> arr){
	for(int i=0; i<arr.size(); i++){
		cout << "[";
		for(int j=0; j<arr[i].size(); j++){
			cout << arr[i][j];
			if(j != arr[i].size()-1) cout << ", ";
		}
		cout << "] ";
	}
	cout << "\n";
}
