#include<bits/stdc++.h>
using namespace std;

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> new_heap;
        priority_queue<int> Q1, Q2;
        for(int i : a) Q1.push(i);
        for(int i : b) Q2.push(i);
        
        int i = 0, j = 0;
        while(!Q1.empty() && !Q2.empty()){
            if(Q1.top() > Q2.top()){
                new_heap.push_back(Q1.top());  
            	Q1.pop();
            } 
            else{
                new_heap.push_back(Q2.top());  
            	Q2.pop();
            } 
        }
        
        while(!Q1.empty()){
        	new_heap.push_back(Q1.top());  
           	Q1.pop();
        }
        
        while(!Q2.empty()){
        	new_heap.push_back(Q2.top());  
           	Q2.pop();
        }
        
        return new_heap;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n), b(m);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	
	vector<int> arr = mergeHeaps(a,b,n,m);
	for(int i : arr) cout << i<< " ";
	cout<<"\n";
	
	return 0;
}
