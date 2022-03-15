#include<bits/stdc++.h>
using namespace std;

class TreeNode{
	public:
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int val){
			this->val = val;
			left = right = NULL;
		}
};

void display(TreeNode* root);
TreeNode* createTree(vector<string>& arr, int& idx);


bool isValidBST(TreeNode* root){
        if(!root){
            MinMaxPair mp = new MinMaxPair();
            return mp;
        }
        
        MinMaxPair lp = isValidBST(root->left);
        MinMaxPair rp = isValidBST(root->right);
        
        MinMaxPair p = new MinMaxPair();
        p.isBST = isValidBST(root->left) && isValidBST(root->right) && (root->val>lp.max_val && root->val<rp.min_val);
        p.min_val = min(root->val,min(lp.min_val,rp.min_val));
        p.max_val = max(root->val,max(lp.max_val,rp.max_val));
        return p;
}
 










void getPreOrder(TreeNode* node, vector<int>& preOrder){
        if(!node) return;
        getPreOrder(node->left,preOrder);
        preOrder.push_back(node->val);
        getPreOrder(node->right,preOrder);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> preOrder;
        getPreOrder(root,preOrder);
        int n = preOrder.size();
        
        for(int i=1; i<n; i++){
            if(preOrder[i] <= preOrder[i-1]) return false; 
        }
        return true;
    }

int main(){
	int n;
	cin >> n;
	vector<string> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	int idx = 0;
	TreeNode* root = createTree(arr,idx);
	
	if(isValidBST(root)) cout << "true";
	else cout << "false";
	cout << "\n";
		
	return 0;
}
























void display(TreeNode* node){
	if(!node) return;
	cout << node->val << " "; 
	display(node->left);
	display(node->right);
}


TreeNode* createTree(vector<string>& arr, int& idx){
	if(idx >= arr.size() || arr[idx] == "null"){
		idx++;
		return NULL;
	}
	
	TreeNode* root = new TreeNode(stoi(arr[idx]));
	idx++;
	root->left = createTree(arr,idx);
	root->right = createTree(arr,idx);
	return root;
}




