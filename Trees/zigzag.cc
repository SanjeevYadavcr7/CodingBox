#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	vector<struct Node*> children;
	Node(int node_data){
		data = node_data;
		children = {};
	}
};

void levelOderZigZagHelper(queue<struct Node*> q, int row){
	queue<Node*> temp_q;
	vector<int> arr;
	while(!q.empty()){
		Node* node = q.front();
		arr.push_back(node->data);
		q.pop();
		for(Node* child: node->children) temp_q.push(child);
	}
	
	if(row & 1) for(int i=arr.size()-1;i>=0;i--) cout<<arr[i]<<" ";
	else for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
	cout<<endl;
	
	if(!temp_q.empty()) levelOderZigZagHelper(temp_q,row+1);
}

void levelOderZigZag(Node* node){
	queue<Node*> q;
	q.push(node);
	levelOderZigZagHelper(q,0);
}

int main(){
	struct Node* root;
	stack<struct Node*> stk;
	vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
	for(int i=0;i<arr.size();i++){
		int node_data = arr[i]; 
		struct Node* new_node = new Node(node_data);
		if(arr[i] == -1) stk.pop();
		else{
			if(stk.empty()) root = new_node;
			else stk.top()->children.push_back(new_node);
			stk.push(new_node);
		}	
	}
	
	levelOderZigZag(root);

	return 0;
}
