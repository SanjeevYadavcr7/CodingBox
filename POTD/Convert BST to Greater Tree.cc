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
void display(TreeNode* root);

void convertBSTHelper(TreeNode* node, int& _val){
	if(!node) return;
	
	convertBSTHelper(node->right,_val);
	node->val += _val;
	_val = node->val;
	convertBSTHelper(node->left,_val);
}

TreeNode* convertBST(TreeNode* root) {
	int _val = 0;
	convertBSTHelper(root,_val);
	return root;
}

int main(){
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(1);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(2);
	root->left->right->right = new TreeNode(3);
	root->right = new TreeNode(6);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(7);
	root->right->right->right = new TreeNode(8);

	cout << "Tree = "; display(root); cout << "\n";
	root = convertBST(root);
	cout << "Tree = "; display(root); cout << "\n";

	return 0;
}









/*---------- void display(root) --------------*/

void display(TreeNode* node){
	if(!node) return;
	display(node->left);
	cout << node->val << " ";
	display(node->right);
}
