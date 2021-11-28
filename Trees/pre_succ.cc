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
void multisolver(Node* root, int depth);


Node* pre;
Node* suc;
int state = 0;

void getPreSucc(Node* node, int node_data){
	if(state == 0){
		if(node->data == node_data) state = 1;
		else pre = node;
	}
	else if(state == 1){
		suc = node;
		state = 2;
	}
	for(Node* child: node->children) getPreSucc(child, node_data);
}


int main(){	
	vector<int> arr = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,40,100,-1,-1,-1};
	
	Node* root;	
	root = construct(root, arr);
	
	int x;
	cout<<"Enter node = ";
	cin>>x;
	getPreSucc(root,x);		
	cout<<"Predecessor = "<<pre->data<<endl;
	cout<<"Successor = "<<suc->data<<endl;
	
	return 0;
}













void multisolver(Node* root, int depth){
	size++;
	height = max(height, depth);
	max_node = max(max_node, root->data);
	min_node = min(min_node, root->data);
	for(Node* child: root->children) multisolver(child, depth+1);
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
