#include<bits/stdc++.h>
using namespace std;

class TreeNode{   
    public:
        int val = 0;
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;
        TreeNode(int val){
            this->val = val;
        }
};

int max_len = 0;
    
void traverseTree(TreeNode* node, int len, string dir){
    if(!node) return;
        
    if(dir == "L"){
        if(node->left) traverseTree(node->left,1,"L");
        if(node->right) traverseTree(node->right,len+1,"R");
    }
    else{
        if(node->left) traverseTree(node->left,len+1,"L");
        if(node->right) traverseTree(node->right,1,"R");
    }
    max_len = max(max_len,len);
    } 
    
int longestZigZag(TreeNode* root) {      
    if(root->left) traverseTree(root->left,1,"L");
    if(root->right) traverseTree(root->right,1,"R");
    return max_len;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->left->right->left = new TreeNode(1);
    root->left->right->left->right = new TreeNode(1);
    root->left->right->right = new TreeNode(1);
    root->right = new TreeNode(1);

    int longest_path = longestZigZag(root);
    cout << longest_path << "\n";
 
    return 0;
}