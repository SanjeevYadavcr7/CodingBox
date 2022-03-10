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
void display(TreeNode* node);

TreeNode* buildTree(int beg, int end, vector<int>& inorder){
	if(beg > end) return NULL;
	
	int mid = (beg+end)/2;
	TreeNode* curr = new TreeNode(inorder[mid]);
	curr->left = buildTree(beg,mid-1,inorder);
	curr->right = buildTree(mid+1,end,inorder);
	return curr;
}

TreeNode *constructFromInOrder(vector<int> &inorder){
	int n = inorder.size();
	TreeNode* root = buildTree(0,n-1,inorder);
	return root;
}

int main(){
	int n;
	cin >> n;
	vector<int> inorder(n);
	for(int i=0; i<n; i++) cin >> inorder[i];
	
	TreeNode* root = constructFromInOrder(inorder);
	display(root);
	
	return 0;
}


























void display(TreeNode* node){
	if(!node) return;

	cout << node->val << " ";
	display(node->left);
	display(node->right);
}
