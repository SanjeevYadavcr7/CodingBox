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

TreeNode* buildTree(int psi, int pse, vector<int>& pre, int pos, int poe, vector<int>& post){
	if(psi > pse || pos > poe) return NULL;
	
	TreeNode* root = new TreeNode(pre[psi]);
	if(psi == pse) return root;
	int idx = pos;
	while(post[idx] != pre[psi+1]) idx++;
	in total = idx - pos + 1;
	
	root->left =  buildTree(psi+1,psi+total, pre, pos, idx, post);
	root->right = buildTree(psi+total+1, pse, pre, idx+1, poe-1, post);
	return root;
}

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder){
	int n = preorder.size();
	TreeNode* root = buildTree(0,n-1,preorder,0,n-1,postorder);
	return root;
}

int main(){
	int n;
	cin >> n;
	vector<int> preOrder(n), postOrder(n);
	for(int i=0; i<n; i++) cin >> preOrder[i];
	for(int i=0; i<n; i++) cin >> postOrder[i];
		
	TreeNode* root = constructFromPrePost(preOrder,postOrder);
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
