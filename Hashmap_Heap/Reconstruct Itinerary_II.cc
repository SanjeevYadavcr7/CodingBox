#include "bits/stdc++.h"
using namespace std;

vector<string> res;
unordered_map<string,multiset<string>> airports;

void visit(string city) {
	while(airports[city].size()) {
		string next_city = *airports[city].begin();
		airports[city].erase(airports[city].begin());
		visit(next_city);
	}
	res.push_back(city);
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
	for(auto i : tickets) airports[i[0]].insert(i[1]);
	visit("JFK");
	reverse(res.begin(), res.end());
	return res;
}

int main(){
    int n;
    cin >> n;
	vector<vector<string>> tickets(n,vector<string>(2));
	for(int i=0; i<n; i++)
		for(int j=0; j<2; j++) cin >> tickets[i][j];
	
	findItinerary(tickets);
	
	return 0;
}
