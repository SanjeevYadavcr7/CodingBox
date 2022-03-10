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

TreeNode* buildTree(int beg, int end, vector<int>& postorder){
	if(beg > end) return NULL;
	
	TreeNode* curr = new TreeNode(postorder[end]);
	int idx = beg;
	while(postorder[idx] < postorder[end]) idx++;
	
	curr->left = buildTree(beg,idx-1,postorder);
	curr->right = buildTree(idx,end-1,postorder);
	return curr;
}

TreeNode *constructFromPostOrder(vector<int> &postorder){
	int n = postorder.size();
	TreeNode* root = buildTree(0,n-1,postorder);
	return root;
}

int main(){
	int n;
	cin >> n;
	vector<int> postorder(n);
	for(int i=0; i<n; i++) cin >> postorder[i];
	
	TreeNode* root = constructFromPostOrder(postorder);
	display(root);
	
	return 0;
}


























void display(TreeNode* node){
	if(!node) return;

	cout << node->val << " ";
	display(node->left);
	display(node->right);
}
