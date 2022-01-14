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

void modifyHelper(Node* node, int &val){
	if(!node) return;
	
	modifyHelper(node->right,val);
	node->data += val;
	val = node->data;
	modifyHelper(node->left,val);
}

Node* modify(Node *root){
	int val = 0;
    modifyHelper(root,val);
	return root;
}


void display(Node* root){
	if(!root) return;
	
	display(root->left);
	cout<<root->data<<" ";
	display(root->right);
}

int main(){
	Node* root = new Node(2);
	root->left = new Node(1);
	root->right = new Node(5);
	root->right->left = new Node(4);
	root->right->right = new Node(7);
	
	cout<<"Tree[] = ";display(root);cout<<"\n";
	root = modify(root);
	cout<<"After Modification....\nTree[] = ";display(root);cout<<"\n";

	return 0;
}
