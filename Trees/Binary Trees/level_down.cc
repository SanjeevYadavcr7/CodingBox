#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int node_data){
		data = node_data;
		left = right = NULL;
	}
};

Node* contructBinaryTree(Node* root,vector<int> arr);

vector<Node*> getPathToRoot(Node* node,int data){
	if(!node){
		vector<Node*> path;
		return path;
	}
	if(node->data == data){
		vector<Node*> path = {node};
		return path;
	}
	
	vector<Node*> path;
	vector<Node*> l_path = getPathToRoot(node->left,data);
	vector<Node*> r_path = getPathToRoot(node->right,data);
	if(l_path.size() > 0){
		l_path.push_back(node);
		path = l_path;
	}
	if(r_path.size() > 0){
		r_path.push_back(node);
		path = r_path;
	}
	return path;
}

void printKLevel(Node* node, int k, Node* blocker){
	if(!node || k<0 || node == blocker) return;
	if(k == 0) cout<<node->data<<"\n";
	printKLevel(node->left,k-1,blocker);
	printKLevel(node->right,k-1,blocker);
}

void printKNodesFar(Node* node, int data, int k){
	vector<Node*> p_to_r = getPathToRoot(node,data);
	for(int i=0;i<p_to_r.size();i++){
		Node* blocker = (i==0) ? NULL : p_to_r[i-1];
		printKLevel(p_to_r[i],k-i, blocker);
	}	
}

int main(){
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		string x;
		cin>>x;
		if(x == "n") arr.push_back(-1);
		else arr.push_back(stoi(x));
	}
	
	Node* root = contructBinaryTree(root,arr);
	
	int data;
	cin>>data;
	int k;
	cin>>k;
	printKNodesFar(root,data,k);
	
	return 0;
}














Node* contructBinaryTree(Node* root, vector<int>arr){
	stack<pair<Node*,int>> stk;
	root = new Node(arr[0]);
	stk.push({root,1});
	
	int i = 0;
	while(!stk.empty()){
		auto it = stk.top();
		int state = it.second;
		if(state == 1){
			i++;
			stk.top().second++;
			if(arr[i] != -1){
				Node* new_node = new Node(arr[i]);
				stk.top().first->left = new_node;
				stk.push({new_node,1});
			}
			else stk.top().first->left = NULL;
		}
		else if(state == 2){
			i++;
			stk.top().second++;
			if(arr[i] != -1){
				Node* new_node = new Node(arr[i]);
				stk.top().first->right = new_node;
				stk.push({new_node,1});
			}
			else stk.top().first->right = NULL;
		}
		else stk.pop();
	}
	return root;
}

































