#include<iostream>
using namespace std;

int getSteps(int x, int y){
	if(x<y){
		int diff = abs(y-x);
		int steps = diff/2;
		int rem = diff%2;
		if(rem == 0) return steps;
		return steps+2;
	}
	else if(x == y) return 0;
	else{
		int diff = abs(x-y);
		return diff;
	}
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		cout<<getSteps(x,y)<<"\n";
	}
	return 0;
}
