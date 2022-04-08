#include<bits/stdc++.h>
using namespace std;

class KthLargest {	
	public:
	priority_queue<int, vector<int>, greater<int>> Q;
		int idx;
		
		KthLargest(int k, vector<int>& nums) {
		    idx = k;
		    for(int& i : nums){
		    	Q.push(i);
		    	if(Q.size() > k) Q.pop();
		    }
	}
		
	int add(int val) {
		if(Q.empty() || Q.size() < idx){
			Q.push(val);   
		    return Q.top();
		}
		    
		if(Q.top() >= val) return Q.top();
		Q.pop();
		Q.push(val);
		return Q.top();
	}
};
int main(){
	// Custom Data Structure
	// Initialization => O(NLogN)
	// Lookup => O(1)

	return 0;
}
