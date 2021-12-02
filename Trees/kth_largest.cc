#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	vector<Node*> children;
	Node(int node_data){
		data = node_data;
	}
};
Node* insert(Node* root, vector<int> arr);
void preOrder(Node* node);


void getArray(Node* node, vector<int>& arr){
	arr.push_back(node->data);
	for(Node* child: node->children) getArray(child, arr);
}

int kthlarge(Node* node, int k){
	vector<int> arr;
	getArray(node,arr);
	sort(arr.begin(), arr.end());
	int n = arr.size();
	int ans = arr[n-k];
	return ans;
}

int main(){
	vector<int> arr = {10,20,-50,-1,60,-1,-1,30,70,-1,-80,110,-1,-120,-1,-1,90,-1,-1,40,-100,-1,-1,-1};
	Node* root = insert(root,arr);
	preOrder(root);
	cout<<endl;
	
	int k;
	cout<<"Enter Data = ";
	cin>>k;
	
	int ans = kthlarge(root,k);
	cout<<ans<<endl;
	
	return 0;
}

























Node* insert(Node* root, vector<int> arr){
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



void preOrder(Node* node){
	cout<<node->data<<" ";
	for(Node* child: node->children) preOrder(child);
}
