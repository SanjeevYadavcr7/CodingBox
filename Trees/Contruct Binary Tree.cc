#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int _val){
		val = _val;
		left = right = NULL;
	}
};
int idx;
void display(TreeNode* node);

TreeNode* buildTree(int l, int r, vector<int>& pre, vector<int>& in, unordered_map<int,int>& mp);

TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder);

int main(){
	int n;
	cin >> n;
	vector<int> preOrder(n), inOrder(n);
	for(int i=0; i<n; i++) cin >> preOrder[i];
	for(int i=0; i<n; i++) cin >> inOrder[i];
	
	idx = 0;
	TreeNode* root = buildTree(preOrder,inOrder);
	display(root);

	return 0;
}











TreeNode* buildTree(int l, int r, vector<int>& pre, vector<int>& in, unordered_map<int,int>& mp){
	if(l > r) return NULL;
	
	TreeNode* curr_node = new TreeNode(pre[idx]);
	int mid = mp[pre[idx++]];
	
	curr_node->left = buildTree(l,mid-1,pre,in,mp);
	curr_node->right = buildTree(mid+1,r,pre,in,mp);
	return curr_node;
}

TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder){
	int n = preOrder.size(), m = inOrder.size();
	if(n == 0 || m == 0 || n != m) return NULL;
	
	unordered_map<int,int> mp;
	for(int i=0; i<n; i++) mp[inOrder[i]] = i;
	
	TreeNode* root = buildTree(0,n-1,preOrder,inOrder,mp); 
	return root;
}


void display(TreeNode* node){
	if(!node) return;
	
	cout << node->val << " ";
	display(node->left);
	display(node->right);
}
