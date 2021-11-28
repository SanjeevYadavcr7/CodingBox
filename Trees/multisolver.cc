#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	vector<Node*> children;
	Node(int node_data){
		data = node_data;
	}
};

int size, height, max_node, min_node;

Node* construct(Node* root, vector<int> arr);
void preOrder(Node* node);
void multisolver(Node* root, int depth);

int main(){	
	vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,40,100,-1,-1,-1};
	
	Node* root;	
	root = construct(root, arr);
	
	preOrder(root);
	cout<<endl;
	
	size = 0, height = 0, max_node = INT_MIN, min_node = INT_MAX; 
	multisolver(root,0);
	cout<<"Size = "<<size<<endl;
	cout<<"Height = "<<height<<endl;
	cout<<"Min Node = "<<min_node<<endl;
	cout<<"Max Node = "<<max_node<<endl;
		
			
	return 0;
}













void multisolver(Node* root, int depth){
	size++;
	height = max(height, depth);
	max_node = max(max_node, root->data);
	min_node = min(min_node, root->data);
	for(Node* child: root->children) multisolver(child, depth+1);
}



void preOrder(Node* node){
	cout<<node->data<<" ";
	for(Node* child: node->children) preOrder(child);
}

Node* construct(Node* root, vector<int> arr){
	stack<Node*> stk;
	for(int i=0;i<arr.size();i++){
		int node_data = arr[i];
		Node* new_node = new Node(node_data);
		if(node_data == -1) stk.pop();
		else{
			if(stk.empty()) root = new_node;
			else stk.top()->children.push_back(new_node);
			stk.push(new_node);
		}
	}
	return root;	
}
