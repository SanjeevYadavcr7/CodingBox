#include<bits/stdc++.h>
using namespace std;

class TreeNode{
	public:
		int val = 0;
		TreeNode* left = NULL;
		TreeNode* right = NULL;
		TreeNode(int val){
			this->val = val;
		}
};

TreeNode* getRightMostNode(TreeNode* leftNode,TreeNode* curr){
	if(leftNode->right != NULL && leftNode->right != curr) leftNode = leftNode->right;
	return leftNode;
}

vector<int> morrisInTraversal(TreeNode* root){
	vector<int> inOrder;
	TreeNode* curr = root;
	
	while(curr != NULL){
		TreeNode* leftNode = curr->left;
		if(leftNode == NULL){
			inOrder.push_back(curr->val);
			curr = curr->right;
		}
		else{
			TreeNode* rightMostNode = getRightMostNode(leftNode,curr);
			if(rightMostNode->right == NULL){
				rightMostNode->right = curr;
				curr = curr->left;
			}
			else{
				rightMostNode->right = NULL;
				inOrder.push_back(curr->val);
				curr = curr->right;
			}
		}	
	}
	return inOrder;
}


int main(){
	

	return 0;
}
