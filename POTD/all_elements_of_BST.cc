#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void getArray(TreeNode* root, vector<int>& arr){
    if(!root) return;
    getArray(root->left,arr);
    arr.push_back(root->val);
    getArray(root->right,arr);
}

vector<int> mergeArray(vector<int>& arr1, vector<int>& arr2){
    int n = arr1.size(), m = arr2.size(), i = 0, j = 0, k = 0;
    vector<int> ans;
    while(i<n && j<m){
        if(arr1[i] < arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }
        else{
            ans.push_back(arr2[j]);
            j++;
        }
    }

    while(i<n){
        ans.push_back(arr1[i]);
        i++;
    }
    while(j<m){
        ans.push_back(arr2[j]);
        j++;
    }
    return ans;
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2){
    vector<int> arr1, arr2;
    getArray(root1, arr1);
    getArray(root2, arr2);
    vector<int> arr3 = mergeArray(arr1,arr2);
    return arr3;
}

int main(){
    
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(3);

    vector<int> ans = getAllElements(root1, root2);
    for(int& i : ans) cout << i << " ";
    cout << "\n";

    return 0;
}