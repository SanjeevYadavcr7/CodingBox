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

// TC: O(N) | SC(*recursive space): O(LogN) 

int kth_node = -1;
void getKthsmallest(TreeNode* node, int& k){
	if(!node || kth_node != -1) return;
	
	getKthsmallest(node->left,k);
	if(kth_node != -1) return;
	if(k == 1){
		 kth_node = node->val;
		 return;
	}
	k--;
	getKthsmallest(node->right,k);
}

int kthSmallest(TreeNode* root, int k) {
	getKthsmallest(root,loc);
	return kth_node;
}

int main(){
	int k;
	cin >> k;
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(2);
	root->left->left->left = new TreeNode(1);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(6);

	int node_val = kthSmallest(root,k);
	cout << node_val << endl;
	
	return 0;
}
