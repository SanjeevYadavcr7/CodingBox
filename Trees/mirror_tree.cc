#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	vector<struct Node*> children;
	Node(int node_data){
		data = node_data;
	}
};

void display(Node* root);

void mirror(Node* root){
	/*
	stack<Node*> stk;
	for(Node* child: root->children){
		stk.push(child);
	}
	root->children = {};
	while(!stk.empty()){
		root->children.push_back(stk.top());
		stk.pop();
	} 
	*/
	for(Node* child: root->children) mirror(child);
	reverse(root->children.begin(), root->children.end());
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
	cout<<"\nAfter Mirroring \n";
	mirror(root);
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
