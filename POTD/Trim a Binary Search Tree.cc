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

TreeNode* trimBST(TreeNode* root, int low, int high){
	if(!root) return NULL;
	
	if(root->val >= low && root->val <= high){
		root->left = trimBST(root->left,low,high);
		root->right = trimBST(root->left,low,high);
		return root;
	}
	
	if(root->val > high) return trimBST(root->left,low,high);
	return trimBST(root->right,low,high);	
}

/* Approach: Old school way of constructing BST by pre-calculating inOrder and preOrder |  
   NOTE: This appraoch may seem very slow but actaully works faster than expected because the nodes     
         which will not be in range [low,high] will be eliminated 

void getInOrder(TreeNode* root, vector<int>& inOrder,int low, int high);
void getPreOrder(TreeNode* root, vector<int>& preOrder,int low, int high);
TreeNode* constructTree(int beg, int end, int& idx, vector<int>& preOrder, unordered_map<int,int>& mp);
TreeNode* makeNewBST(vector<int>& inOrder, vector<int>& preOrder);

TreeNode* trimBST(TreeNode* root, int low, int high){
	vector<int> preOrder, inOrder;
	
	getInOrder(root,inOrder,low,high);
	getPreOrder(root,preOrder,low,high);

	root = makeNewBST(inOrder,preOrder);
	return root;	
}
*/

int main(){
	int low, high;
	cin >> low >> high;
	
	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(1);
	// root->left->right = new TreeNode(2);
	// root->left->right->left = new TreeNode(1);
	root->right = new TreeNode(2);
	
	root = trimBST(root,low,high);
	
	return 0;
}










/*-------------------------------------*/

void display(TreeNode* node){
	if(!node) return;
	
	display(node->left);
	cout << node->val << " ";
	display(node->right);
}

void getInOrder(TreeNode* node, vector<int>& inOrder,int low, int high){
	if(!node) return;
	
	getInOrder(node->left,inOrder,low,high);
	if(low <= node->val && node->val <= high) inOrder.push_back(node->val);
	getInOrder(node->right,inOrder,low,high);
}

void getPreOrder(TreeNode* node, vector<int>& preOrder,int low, int high){
	if(!node) return;
	
	if(low <= node->val && node->val <= high) preOrder.push_back(node->val);
	getPreOrder(node->left,preOrder,low,high);
	getPreOrder(node->right,preOrder,low,high);
}

TreeNode* constructTree(int beg, int end, int& idx, vector<int>& preOrder, unordered_map<int,int>& mp){
	if(beg > end) return NULL;
	
	int node_idx = mp[preOrder[idx]];
	TreeNode* root = new TreeNode(preOrder[idx++]);
	root->left = constructTree(beg,node_idx-1,idx,preOrder,mp);
	root->right = constructTree(node_idx+1,end,idx,preOrder,mp);
	return root;
}

TreeNode* makeNewBST(vector<int>& inOrder, vector<int>& preOrder){
	int n = inOrder.size();
	unordered_map<int,int> mp;
	
	for(int i=0; i<n; i++) mp[inOrder[i]] = i;
	int idx = 0;
	TreeNode* root = constructTree(0,n-1,idx,preOrder,mp);
	return root;
}
