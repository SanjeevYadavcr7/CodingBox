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

TreeNode* increasingBST(TreeNode* root, TreeNode* tail){
	if(!root) return tail;
	TreeNode* res = increasingBST(root->left,root);
	root->left = NULL;
	root->right = increasingBST(root->right,tail);
	return res;
}


/*
TreeNode *pseudo_root = new TreeNode(-1); 
TreeNode* curr = pseudo_root;

void getIncreasingBST(TreeNode* node){
	if(!node) return;
	
	getIncreasingBST(node->left);
	curr->right = new TreeNode(node->val);
	curr = curr->right;
	getIncreasingBST(node->right);
}

TreeNode* increasingBST(TreeNode* root) {	
	getIncreasingBST(root);
	return pseudo_root->right;	
}
*/


int main(){
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(2);
	root->left->left->left = new TreeNode(1);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(6);
	root->right->right = new TreeNode(8);
	root->right->right->left = new TreeNode(7);
	root->right->right->right = new TreeNode(9);
	
	display(root); cout << "\n";
	root = increasingBST(root);		
	display(root); cout << "\n";
		
	return 0;
}




/*----------- Display() -------------*/

void display(TreeNode* root){
	if(!root) return;
	display(root->left);
	cout << root->val << " ";
	display(root->right);
}

