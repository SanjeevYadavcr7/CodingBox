#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val){
		this->val = val;
		left = right = NULL;
	}
};

TreeNode* getRightMostNode(TreeNode* leftNode, TreeNode* curr){
	while(leftNode->right != NULL && leftNode->right != curr) leftNode = leftNode->right;
	return leftNode;
}

void recoverTree(TreeNode* root){
	TreeNode *a = NULL, *b = NULL, *prev = NULL;
	TreeNode* curr = root;
	
	while(curr != NULL){
		TreeNode* leftNode = curr->left;
		if(leftNode == NULL){
			if(prev != NULL && prev->val > curr->val){
				if(a == NULL) a = prev;
				b = curr;
			}
			prev = curr;
			curr = curr->right;
		}
		else{
			TreeNode* RMSNode = getRightMostNode(leftMostNode,curr);
			if(RMSNode->right == NULL){
				RMSNode->right = curr;
				curr = curr->left;
			}
			else{
				RMSNode->right = NULL;
				if(prev->val > curr->val){
					if(a == NULL) a = prev;
					b = curr;
				}
				prev = curr;
				curr = curr->right;
			}
		}
	}
	
	if(a != NULL){
		int temp = a->val;
		a->val = b->val;
		b->val = temp;
	}
}


int main(){
	
	
	return 0;	
}
