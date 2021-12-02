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

int ceil_num;
int floor_num;
int state = 0;
void ceilAndFloor(Node* node, int data){
    if(node->data < data) floor_num = max(floor_num, node->data);
   	if(node->data > data) ceil_num = min(ceil_num, node->data);
   	
    for(Node* child: node->children) ceilAndFloor(child, data);
}

int main(){
	vector<int> arr = {10,20,-50,-1,60,-1,-1,30,70,-1,-80,110,-1,-120,-1,-1,90,-1,-1,40,-100,-1,-1,-1};
	Node* root = insert(root,arr);
	preOrder(root);
	cout<<endl;
	
	int n;
	cout<<"Enter Data = ";
	cin>>n;
	
	ceil_num = INT_MAX;
	floor_num = INT_MIN;
	ceilAndFloor(root,n);
	cout<<endl<<ceil_num<<" | "<<floor_num<<endl;
	
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
