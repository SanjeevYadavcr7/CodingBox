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
void display(TreeNode* node);

void getPreOrder(TreeNode* node, string& preOrder){
    if(!node) return;
    char ch = node->val+'0';
    preOrder.push_back(ch);
    getPreOrder(node->left,preOrder);
    getPreOrder(node->right,preOrder);
}

void getInOrder(TreeNode* node, string& inOrder){
    if(!node) return;
    getInOrder(node->left,inOrder);
    char ch = node->val+'0';
    inOrder.push_back(ch);
    getInOrder(node->right,inOrder);
}

string serialize(TreeNode* root) {
    string preOrder, inOrder;
    getPreOrder(root,preOrder);
    getInOrder(root,inOrder);
    string hash = preOrder + "|" + inOrder;
    return hash;
}

int idx;
TreeNode* constructTree(int beg, int end, string preOrder, string inOrder, unordered_map<char,int>& mp){
    if(beg > end) return NULL;

    int node_val = preOrder[idx]-'0';
    TreeNode* root = new TreeNode(node_val);
    int mid = mp[preOrder[idx++]];
    
    root->left = constructTree(beg,mid-1,preOrder,inOrder,mp);
    root->right = constructTree(mid+1,end,preOrder,inOrder,mp);
    return root;
}

TreeNode* deserialize(string data) {
    if(data == "|") return NULL;
    int id;
    for(int i=0; i<data.size(); i++){
        if(data[i] == '|'){
            id = i;
            break;
        }
    }
    string preOrder = data.substr(0,id);
    string inOrder = data.substr(id+1);
    int n = preOrder.size(), m = inOrder.size();
    if(n == 0 || m == 0 || n != m) return NULL;

    unordered_map<char,int> mp;
    for(int i=0; i<m; i++) mp[inOrder[i]] = i;
    idx = 0;
    TreeNode* root = constructTree(0,n-1,preOrder,inOrder,mp);
    return root;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    display(root);cout << "\n";
    
    string encoding = serialize(root);
    root = deserialize(encoding);
    
    display(root);
    cout << "\n";

    return 0;
}





















void display(TreeNode* node){
    if(!node){
        cout << "null ";
        return;
    }
    cout << node->val << " ";
    display(node->left);
    display(node->right);
}