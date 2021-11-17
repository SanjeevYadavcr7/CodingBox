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

void DisplayLevelOrder( struct Node* root){
	queue<struct Node*> q;
	q.push(root);
	while(!q.empty()){
		struct Node* temp = q.front();
		q.pop();
		cout<<temp->data<<" ";
		for(struct Node* child: temp->children){
			q.push(child);
		}
	}
	cout<<".\n";
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
	
	DisplayLevelOrder(root);
	
	return 0;
}
