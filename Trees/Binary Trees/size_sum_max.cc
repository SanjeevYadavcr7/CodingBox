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

struct Node* constructBinaryTree(Node* root, vector<int> arr){
	stack<pair<Node*,int>> stk;
	int root_data = arr[0];
	root = new Node(root_data);
	stk.push({root,1});
	
	int i=0;
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

void display(Node* root){
	if(!root) return;
	
	string str = "";
	str += (!root->left) ? ". " : to_string(root->left->data);
	str += " <- " + to_string(root->data) + " -> ";
	str += (!root->right) ? ". " : to_string(root->right->data);
	cout<<str<<endl;  
	
	display(root->left);
	display(root->right);
}

int size(Node* node){
	if(!node) return 0;
	int left_size = size(node->left);
	int right_size = size(node->right);
	int tree_size = left_size+right_size+1;
	return tree_size;
}

int height(Node* node){
	if(!node) return 0;
	int lh = height(node->left);
	int rh = height(node->right);
	int h = max(lh,rh)+1;
	return h;
}

int maximum(Node* node){
	if(!node) return 0;
	int max_node = node->data;
	int lnv = maximum(node->left);
	int rnv = maximum(node->right);
	max_node = max(max_node, max(lnv,rnv));
	return max_node;
}

int treeSum(Node* root){
	if(!root) return 0;
	int tsum = root->data + treeSum(root->left) + treeSum(root->right);
	return tsum; 
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

	Node* root = constructBinaryTree(root,arr);
	//cout<<"\nTree = \n";
	//display(root);
	cout<<"Size = "<<size(root)<<endl;
	cout<<"Sum = "<<treeSum(root)<<endl;
	cout<<"Max = "<<maximum(root)<<endl;
	cout<<"Height = "<<height(root)<<endl;
	
	return 0;
}
