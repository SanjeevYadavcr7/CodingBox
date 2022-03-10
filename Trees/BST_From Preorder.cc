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
    TreeNode* buildBST(int beg, int end, vector<int>& preorder){
        if(beg > end) return NULL;
        
        TreeNode* curr = new TreeNode(preorder[beg]);
        int idx = beg+1;
        while(idx < preorder.size() && preorder[idx] < preorder[beg]) idx++;
        
        curr->left = buildBST(beg+1,idx-1,preorder);
        curr->right = buildBST(idx,end,preorder);
        return curr;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode* root = buildBST(0,n-1,preorder); 
        return root;
    }


int main(){
	int n;
	cin >> n;
	vector<int> preorder(n);
	for(int i=0; i<n; i++) cin >> preorder[i];
	
	TreeNode* root = bstFromPreorder(preorder);
	display(root);
	
	return 0;
}


























void display(TreeNode* node){
	if(!node) return;

	cout << node->val << " ";
	display(node->left);
	display(node->right);
}
