/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int,TreeNode*> mp;
        
        unordered_map<int,bool> child_mp;
        
        for(int i=0; i<n; i++){
            int par = descriptions[i][0], child = descriptions[i][1], isLeft = descriptions[i][2];
            child_mp[child] = true;
            if(mp[par] == NULL) mp[par] = new TreeNode(par);   
            if(mp[child] == NULL) mp[child] = new TreeNode(child);
            
            if(isLeft) mp[par]->left = mp[child];
            else mp[par]->right = mp[child];
        }
        
        for(int i=0; i<n; i++){
            int par = descriptions[i][0];
            if(child_mp[par] == false) return mp[par];
        }
        return NULL;
    }
};