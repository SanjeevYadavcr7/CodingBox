#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	vector<struct Node*> children;
	Node(int node_data){
		data = node_data;
	}
};

void display(Node* node);

bool IsLeaf(Node* node){
	if(node && node->children.size() == 0) return true;
	return false;
}

void RemoveLeaves(Node* root){
	/*
	queue<Node*> stk;
	for(Node* child: root->children){
		stk.push(child);
	}
	root->children = {};
	while(!stk.empty()){
		if(!IsLeaf(stk.front())) root->children.push_back(stk.front());
		stk.pop();
	}
	*/
	auto it = root->children.end();
	--it;
	// running loop in reverse order to avoid concurrent removal problem in array 
	for(int i=root->children.size()-1; i>=0; i--){
		Node* child = root->children[i];
		if(IsLeaf(child)) root->children.erase(it);
		--it;
	}
	
	for(Node* child: root->children) RemoveLeaves(child);
	
}

int main(){	
	vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
	struct Node* root;
	stack<Node*> stk;
	for(int i=0;i<arr.size();i++){
		int node_data = arr[i];
		Node* new_node = new Node(node_data);
		if(arr[i] == -1) stk.pop();
		else{
			if(stk.empty()) root = new_node;
			else stk.top()->children.push_back(new_node);
			stk.push(new_node);
		}
	}

	display(root);
	cout<<"\nRemoving Leaves \n";
	RemoveLeaves(root);
	display(root);
	
	return 0;
}






















void display(Node* root){
	string path = to_string(root->data) + " -> ";
	for(Node* child: root->children){
		path += to_string(child->data) + ", ";
	}
	cout<<path<<".\n";
	for(Node* child: root->children) display(child);
}
