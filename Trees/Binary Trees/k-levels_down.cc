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
Node* contructBinaryTree(Node* root, vector<int>arr);
void display(Node* node);

/*
void kLevelsDown(Node* node, int k){
	queue<Node*> q;
	q.push(node);
	Node* null_node = new Node(-1);
	q.push(null_node);
	
	int level = 0;
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		if(temp->data == -1){
			level++;
			if(q.empty()) break;
			Node* null_node = new Node(-1);
			q.push(null_node);
		}
		else{
			if(level == k) cout<<temp->data<<"\n";
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}  
}
*/

void kLevelsDown(Node* node, int k){
	if(!node || k<0) return;
	if(k == 0) cout<<node->data<<"\n";
	kLevelsDown(node->left,k-1);
	kLevelsDown(node->right, k-1);
}

int main(){
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		string temp;
		cin>>temp;
		if(temp == "n") arr.push_back(-1);
		else arr.push_back(stoi(temp));
	}
	
	Node* root = contructBinaryTree(root,arr);
	
	int k;
	cin>>k; 
	kLevelsDown(root, k);
	
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

void traversal(Node* node){
	if(!node) return;

	cout<<node->data<<" ";
	traversal(node->left);
	traversal(node->right);
}

void display(Node* node){
	if(!node) return;
	
	string str = "";
	str += (!node->left) ? "." : to_string(node->left->data);
	str += " <- " + to_string(node->data) + " -> ";
	str += (!node->right) ? "." : to_string(node->right->data);
	cout<<str<<endl;
	
	display(node->left);
	display(node->right);
}
