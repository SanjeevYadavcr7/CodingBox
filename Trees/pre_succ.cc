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
//void preOrder(Node* node);
void multisolver(Node* root, int depth);

int loc = -1, temp_loc = 0;
void preOrder(Node* node, vector<int> &path, int node_data){
	if(node->data == node_data){
		loc = temp_loc;
	}
	temp_loc++;
	path.push_back(node->data);
	for(Node* child: node->children) preOrder(child, path, node_data);
}

Node* pre;
Node* suc;

void getPreSucc(Node* node, int node_data){
	0
	+++70vector<int> path;
	preOrder(node, path, node_data);
	int p = path[loc-1], s = path[loc+1];
	pre = new Node(p);
	suc = new Node(s);
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
