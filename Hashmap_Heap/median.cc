#include<bits/stdc++.h>
using namespace std;

class MedianPriorityQueue{
	public: 
		priority_queue<int> left;
		priority_queue<int, vector<int>, greater<int>> right;
		
		void add(int val){
			int l_size = left.size(), r_size = right.size();
			if(size() == 0) left.push(val);
			else if(l_size > 0 && left.top() >= val) left.push(val);
			else right.push(val);
				
			int len_diff = abs(l_size - r_size);
			if(len_diff > 2){
				if(l_size > r_size){
					right.push(left.top());
					left.pop();
				}
				else{
					left.push(right.top());
					right.pop();
				}
			}
		}
		
		int pop(){
			if(size() == 0){
				cout<<"Underflow\n";
				return -1;
			}
			int median = peek();
			if(left.size() > right.size()) left.pop();
			else right.pop();
			return median;
		}
		
		int peek(){
			if(size() == 0){
				cout<<"Underflow\n";
				return -1;
			}
			if(left.size() > right.size()) return left.top();
			return right.top();
		}
		
		int size(){
			return left.size() + right.size();
		}
};

int main(){
	MedianPriorityQueue pq;
	string str;
	cin>>str;
	while(str != "quit"){
		if(str == "add"){
			int val;
			cin>>val;
			pq.add(val);
		}
		else if(str == "remove"){
			int val = pq.pop();
			if(val != -1) cout<<val<<endl;
		}
		else if(str == "peek") cout<<pq.peek()<<endl;
		else if(str == "size") cout<<pq.size()<<endl;
		cin>>str;
	}

	return 0;
}
