#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	vector<struct Node*> children;
	Node(int node_data){
		data = node_data;	
	}
};

Node* insert(Node* root);
void preOrder(Node* root);

vector<int> getNodePath(Node* node, int node_data){
	if(node->data == node_data){
		vector<int> path = {node_data};
		return path;
	}
	for(Node* child: node->children){
		vector<int> path = getNodePath(child,node_data);
		if(path.size() > 0){
			path.push_back(node->data);
			return path;
		}
	}
	vector<int> path;
	return path;
}

int main(){
	struct Node* root;
	root = insert(root);	
	preOrder(root);
	cout<<endl;
	
	int item;
	cout<<"Enter node to get the path = ";
	cin>>item;
	vector<int> path = getNodePath(root, item);
	for(int i: path) cout<<i<<" ";
	cout<<endl;
	
	
	return 0;
}








































void preOrder(Node* node){
	cout<<node->data<<" ";
	for(Node* child: node->children){
		preOrder(child);
	}
}


Node* insert(Node* root){
	vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
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
	return root;
}
