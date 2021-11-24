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
void preOrder(Node* root);

bool search(Node* node, int item, vector<int> &path){
	if(node->data == item){
		path.push_back(node->data);
		return true;
	}
	for(Node* child: node->children){
		if(search(child, item , path)){
			path.push_back(node->data);
			return true;
		} 	
	}
	return false;
}

void getPath(Node* root, int item){
	vector<int> path;
	search(root, item, path);
	for(int i: path) cout<<i<<" ";
}

int main(){	
	int item;
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

	preOrder(root);
	cout<<"\nEnter item to be searched = ";
	cin>>item;
	getPath(root, item);
	cout<<endl;
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

void preOrder(Node* root){
	if(!root) return;
	cout<<root->data<<" ";
	for(Node* child: root->children){
		preOrder(child);
	}
}	
