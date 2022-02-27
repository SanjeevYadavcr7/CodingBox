#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int widthOfBinaryTree(TreeNode* root){
	if(!root) return 0;
	
	int max_width = 0;
	queue<pair<int,TreeNode*>> Q;
	Q.push({0,root});
	
	while(!Q.empty()){
		auto root_node = Q.front();
		int l = root_node.first;
		int r = INT_MIN;	
		int size = Q.size();
		while(size--){
			auto node = Q.front();
			Q.pop();
			int curr_val = node.first;
			r = max(curr_val,r);
			if(node.second->left) Q.push({2*curr_val+1,node.second->left});
			if(node.second->right) Q.push({2*curr_val+2,node.second->right}); 
		}	
		max_width = max(max_width,r-l+1);
	}
	return max_width;
}

int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(1);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(1);
	root->left->right->right = new TreeNode(1);
	root->left->right->right->left = new TreeNode(2);
	root->left->right->right->left->left = new TreeNode(2);
	root->left->right->right->left->left->left = new TreeNode(2);
	root->left->right->right->left->right = new TreeNode(2);
	root->left->right->right->left->right->left = new TreeNode(2);
	root->left->right->right->right = new TreeNode(2);
	root->left->right->right->right->left = new TreeNode(2);
	root->left->right->right->right->left->right = new TreeNode(2);
	root->left->right->right->right->right = new TreeNode(2);
	root->left->right->right->right->right->right = new TreeNode(2);
	
	root->right = new TreeNode(1);
	root->right->left = new TreeNode(1);
	root->right->right = new TreeNode(1);
	
	int width = widthOfBinaryTree(root);	
	cout << width << "\n";

	return 0;
}
