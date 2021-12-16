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

void getLeftNodes(Node* node, vector<int>& left_nodes,int level){
	if(!node) return;
	
	if(level == left_nodes.size()) left_nodes.puhs_back(node->data);
	getLeftNodes(node->left,left_nodes,level+1);
	getLeftNodes(node->right,left_nodes,level+1);
}

void leftViewOfBinaryTree(Node* node){
	vector<int> left_nodes;
	getLeftNodes(node,left_nodes,0);
	return left_nodes;
}

int main(){

	return 0;
}
