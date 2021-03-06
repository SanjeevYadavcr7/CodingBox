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


vector<Node*> getPathToRoot(Node* node, int data){
	if(!node){
		vector<Node*> path;
		return path;
	}
	
	if(node->data == data){
		vector<Node*> path = {node};
		return path;
	}
	
	vector<Node*> path;
	vector<Node*> l_node = getPathToRoot(node->left,data);
	if(l_node.size() > 0){
		l_node.push_back(node);
		path = l_node;
	}
	
	vector<Node*> r_node = getPathToRoot(node->right,data);	
	if(r_node.size() > 0){
		r_node.push_back(node);
		path = r_node;
	}
	return path;
}

void printKLevel(Node* node, int k, Node* prev_temp){
	if(!node || k<0) return;
	if(node->data == prev_temp->data) return;
	if(k == 0) cout<<node->data<<"\n";	
	printKLevel(node->left,k-1,prev_temp);
	printKLevel(node->right,k-1,prev_temp);
}

void printKNodesFar(Node* node, int data, int k){
	vector<Node*> pathToRoot = getPathToRoot(node,data);
	for(int i=1;i<pathToRoot.size();i++){
		Node* temp = pathToRoot[i];
		Node* prev_temp = pathToRoot[i-1];
		if(k<i) break;
		printKLevel(temp,k-i,prev_temp);
	}
}

//vector<int> arr = {50 25 12 1 6 n n 7 n n 2 8 n n 9 n n 37 3 n 10 n n 4 n 11 	 };

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
	
	int data;
  	cin >> data;
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
