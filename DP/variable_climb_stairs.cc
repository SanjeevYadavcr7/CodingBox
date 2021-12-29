#include<bits/stdc++.h>
using namespace std;

int climb_stairs(int arr[], int curr_floor, int target_floor, vector<int>& mem){
	if(curr_floor > target_floor) return 0;
	if(curr_floor == target_floor){
		//cout<<"I'm on top floor\n";
		return 1;
	}
	
	if(mem[curr_floor]) return mem[curr_floor];
	//cout<<"I'm on "<<curr_floor<<" floor\n";
	
	int max_steps = arr[curr_floor];
	for(int next_step = 1; next_step <= max_steps; next_step++){
		int new_floor = curr_floor + next_step;
		mem[curr_floor] += climb_stairs(arr,new_floor,target_floor,mem);
	}
	return mem[curr_floor];
}

int cs(int arr[], int n){
	vector<int> mem(n+1,0);
	int ways = climb_stairs(arr,0,n,mem);
	return ways;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	int ways_to_climb = cs(arr,n);
	cout<<ways_to_climb<<"\n";
	
	return 0;
}
