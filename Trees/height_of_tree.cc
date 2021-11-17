#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	vector<struct Node*> children;
	Node(int node_data){
		data = node_data;
		children = {};
	}
};
void display(Node* root){
	string str = to_string(root->data)+" : ";
	for(struct Node* child: root->children) str += to_string(child->data)+" ";
	cout<<str<<endl;
	for(struct Node* child: root->children) display(child);
}

int getTreeHeight(struct Node* root){
	if(root == NULL) return 0;
	int mh = 0;
	for(Node* child: root->children){
		int ch = getTreeHeight(child)+1;
		mh = max(ch, mh);
	}
	return mh;
}

int main(){
//	vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
	
	vector<int> arr = {48, 40, 35, 30, -1, -1, 42, -1, -1, 58, 50, -1, 60, -1, -1, -1};
	
	int n = arr.size();
	struct Node* root;
	stack<struct Node*> stk;
	
	for(int i=0;i<n;i++){
		if(arr[i] == -1) stk.pop();
		else{
			struct Node* new_node = new Node(arr[i]);
			if(stk.empty()) root = new_node;
			else stk.top()->children.push_back(new_node);
			stk.push(new_node);
		}
	}
	
	// display(root);
	int h = getTreeHeight(root);
	cout<<h<<endl;
	
	
	return 0;
}
