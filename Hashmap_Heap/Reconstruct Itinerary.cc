#include "bits/stdc++.h"
using namespace std;

void findItinerary(vector<vector<string>>& tickets) {
	string src = "";
	vector<string> res;
	unordered_map<string,bool> city;
	unordered_map<string,string> ports;
	
	for(auto i : tickets) ports[i[0]] = i[1];
	
	for(auto i : tickets) city[i[1]] = true;
	for(auto i : tickets) {
		if(city.find(i[0]) == city.end()) {
			src = i[0];
			break;
		}
	}
	
	while(true) {
		if(ports.find(src) != ports.end()) {
			cout << src << " -> ";
			src = ports[src];
		}
		else {
			cout << src << ".";
			break;
		}
	}
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
