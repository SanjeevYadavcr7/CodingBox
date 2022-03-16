#include<bits/stdc++.h>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	int n = pushed.size();
    stack<int> stk;
        
    int i = 0, j = 0;
    while(i<n && pushed[i] != popped[0]) stk.push(pushed[i++]);
    stk.push(pushed[i++]);
    
    while(i<n || !stk.empty()){
    	if(!stk.empty() && stk.top() == popped[j]){
    		stk.pop();
    		j++;
    	}
    	else{
    		if(i<n) stk.push(pushed[i++]);
    		else return false;
    	}
    } 
    return stk.empty();
}

int main(){
	int n;
	cin >> n;
	vector<int> pushed(n), popped(n);
	for(int i=0; i<n; i++) cin >> pushed[i];
	for(int i=0; i<n; i++) cin >> popped[i];
	
	if(validateStackSequences(pushed,popped)) cout << "true\n";
	else cout << "false\n";
	
	return 0;
}
