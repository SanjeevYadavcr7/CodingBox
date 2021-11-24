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

void preOrder(Node* root){
	if(!root) return;
	cout<<root->data<<" ";
	for(Node* child: root->children){
		preOrder(child);
	}
}

Node* getTail(Node* node){
	while(node->children.size() == 1){
		node = node->children[0];
	}
	return node;
}

void LineariseTree(Node* root){
	
	for(Node* child: root->children) LineariseTree(child);
	
	while(root->children.size() > 1){
		Node* lc = root->children[root->children.size()-1];
		root->children.pop_back();
		Node* sl = root->children[root->children.size()-1];
		Node* slt = getTail(sl);
		slt->children.push_back(lc);
	}
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

	LineariseTree(root);
	display(root);
	preOrder(root);
	/*
	cout<<"\nLinearising Tree\n";
	
	
	*/
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
