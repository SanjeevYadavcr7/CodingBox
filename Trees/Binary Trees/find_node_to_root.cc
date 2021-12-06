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

bool findNode(Node* node, int data){
	if(!node) return false;
    
    if(node->data == data) return true;
    return (findNode(node->left,data) || findNode(node->right,data));
}
 
vector<int> nodeToRootPath(Node* node, int data){
	if(!node){
		vector<int> path;
		return path;
	}
	if(node->data == data){
		vector<int> path = {data};
		return path;
	}
	
	vector<int> path;
	vector<int> l_path = nodeToRootPath(node->left,data);
	vector<int> r_path = nodeToRootPath(node->right,data);
	if(l_path.size() > 0){
		l_path.push_back(node->data);
		path = l_path;
	} 
	else if(r_path.size() > 0){
		r_path.push_back(node->data);
		path = r_path;
	}
	return path;
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
	
	int x;
	cin>>x;
	vector<int> path;
	if(findNode(root,x)){
		cout<<"true\n";
		path = nodeToRootPath(root,x);
	} 
	else cout<<"false\n";
	
	cout<<"[";
	for(int i=0;i<path.size();i++){
		cout<<path[i];
		if(i != path.size()-1) cout<<", ";
	} 	
	cout<<"]\n";
	
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
