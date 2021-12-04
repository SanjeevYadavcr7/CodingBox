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

struct Node* constructTree(Node* root, vector<int> arr){
	stack<pair<Node*,int>> stk;
	int root_data = arr[0];
	root = new Node(root_data);
	stk.push({root,1});
	
	int idx = 0;
	while(!stk.empty()){
		auto it = stk.top();
		int state = it.second;
		if(state == 1){
			idx++;
			stk.top().second++;
			if(arr[idx] != -1){
				Node* new_node = new Node(arr[idx]);
				stk.top().first->left = new_node;
				stk.push({new_node,1});
			}
			else stk.top().first->left = NULL;
		}	
		else if(state == 2){
			idx++;
			stk.top().second++;
			if(arr[idx] != -1){
				Node* new_node = new Node(arr[idx]);
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
	
	string ans = "";
	ans += (!root->left) ? " . " : to_string(root->left->data)+"";
	ans += " <- " + to_string(root->data) + " -> ";
	ans += (!root->right) ? " . " : to_string(root->right->data)+""; 
	
	cout<<ans<<endl;
	
	display(root->left);
	display(root->right);
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n,0);
	for(int i=0;i<n;i++){
		string temp;
		cin>>temp;
		if(temp == "n") arr[i] = -1;
		else arr[i] = stoi(temp);
	}
	Node* root = constructTree(root,arr);
	cout<<"Root = "<<root->data<<endl;
	display(root);
	
	return 0;
}
