#include<bits/stdc++.h>
using namespace std;

class TreeNode{
	public: 
		int val;
		TreeNode* left = NULL;
		TreeNode* right = NULL;
		TreeNode(int val){
			this->val = val;
		}
};

TreeNode* getRightMostNode(TreeNode* l_node, TreeNode* curr){
	if(l_node->right != NULL && l_node->right != curr) l_node = l_node->right;
	return l_node;
}

void preOrderUsingMorris(TreeNode* root){
	vector<int> preOrder;
	
	TreeNode* curr = root;
	while(curr){
		TreeNode* l_node = curr->left;
		if(!l_node){
			preOrder.push_back(curr->val);
			curr = curr->right;
		}
		else{
			TreeNode* r_node = getRightMostNode(l_node,curr);
			if(!r_node->right){
				// connecting thread
				r_node->right = curr;
				preOrder.push_back(curr->val);
				curr = curr->left;
			}
			else{
				// disconnecting thread
				r_node->right = NULL;
				curr = curr->right;
			}
		}
	}
}

int main(){
	TreeNode* root;
	preOrderUsingMorris(root);

	return 0;
}
