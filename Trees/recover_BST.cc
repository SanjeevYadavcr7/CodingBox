#include<bits/stdc++.h>
using namespace std;

class TreeNode{
	public:
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int val){
			this->val = val;
			left = right = NULL;
		}
};

TreeNode *first, *sec;
TreeNode* prev = new TreeNode(INT_MIN);

void inorder(TreeNode* node){
	if(!node) return;
	
	inorder(node->left);
	if(!first && prev->val > node->val) first = prev;
	if(first && prev->val > node->val) sec = root;
	inorder(node->right);
}

void recoverTree(TreeNode* root){
    inorder(root);    
    int temp = first->val;
    first->val = sec->val;
    sec->val = temp;
}


int main(){

	return 0;
}
