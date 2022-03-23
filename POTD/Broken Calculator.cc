#include<bits/stdc++.h>
using namespace std;

/*
Approach 1: Naive Approach  |  Time: O(2^log(target))  |  Space = O(target)

NOTE: BFS gives TLE hence a better solution is given below

int brokenCalc(int startValue, int target){
	queue<pair<int,int>> Q;
	Q.push({startValue,0});
	
	while(!Q.empty()){
		auto it = Q.front();
		int curr_val = it.first;
		Q.pop();
		
		if(curr_val == target) return it.second;
		
		if(curr_val < target) Q.push({curr_val*2,it.second+1});
		Q.push({curr_val-1,it.second+1});
	}
	return 0;
}

-----------------------------------------------------------------------------------------------------
*/


Approach 2: Optimized Approach | Time: O(log(tar)) |  Space = O(1)

int brokenCalc(int startValue, int target){
	int steps = 0;
    while(target > startValue){
    	if(target & 1) target += 1;
        else target >>= 1;
        steps++;
    }  
    return steps + startValue - target;
}
    
    
int main(){
	int start, tar;
	cin >> start >> tar;
	
	int min_steps = brokenCalc(start,tar);
	cout << min_steps << "\n";

	return 0;
}
