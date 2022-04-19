#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int _val){
		val = _val;
		left = right = NULL;
	}
};
void display(TreeNode* node);

TreeNode* last_node;
TreeNode *invalid_node1, *invalid_node2;

void rectifyNodes(TreeNode* node){
	if(!node) return;
	
	rectifyNodes(node->left);
	if(last_node && last_node->val > node->val){
		if(!invalid_node1) invalid_node1 = last_node;
		invalid_node2 = node;
	}
	last_node = node;
	rectifyNodes(node->right);
}

void recoverTree(TreeNode* root) {	
	if(!root) return;
	last_node = invalid_node1 = invalid_node2 = NULL;
	rectifyNodes(root);
	swap(invalid_node1->val,invalid_node2->val);
}

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->right->left = new TreeNode(2);
	
	display(root); cout << "\n";
	recoverTree(root);
	display(root); cout << "\n";
	
	return 0;
}



/* ------------- Display() ----------------- */

void display(TreeNode* node){
	if(!node) return;
	
	display(node->left);
	cout << node->val << " ";
	display(node->right);
}
