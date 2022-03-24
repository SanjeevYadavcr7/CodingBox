#include<bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int>& people, int limit){
	int n = people.size(), boats = 0;
	sort(people.begin(), people.end());
	
	int i=0, j=n-1;
	int weight = 0;
	while(i <= j){
		// getting total weight in curr boat
		weight = people[i] + people[j];
		
		if(weight <= limit) i++;
		j--;
		// case 1: if both selected persons can sit in curr boat
		// case 2: if both selected persons can't sit => motallu ko doosri boat mein baghao
		
		boats++;
		// boat used
	}	
	return boats;
}

int main(){
	int n,limit;
	cin >> n;
	vector<int> people(n);
	for(int i=0; i<n; i++) cin >> people[i];
	cin >> limit;
	
	int boats = numRescueBoats(people,limit);
	cout << boats << "\n";

	return 0;
}
