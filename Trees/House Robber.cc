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

class robPair{
    public:
        int withrob;
        int withoutrob;
        robPair(int withrob, int withoutrob){
            this->withrob = withrob;
            this->withoutrob = withoutrob;
        }
};

class Solution {
public:
    robPair* doRobbery(TreeNode* root){
        if(!root){
            robPair* rb = new robPair(0,0);
            return rb;
        }
        
        robPair* lp = doRobbery(root->left);
        robPair* rp = doRobbery(root->right);
        robPair* money = new robPair(0,0);
        money->withrob = root->val + lp->withoutrob + rp->withoutrob;
        money->withoutrob = max(lp->withrob, lp->withoutrob) + max(rp->withrob, rp->withoutrob); 
        return money;
    }
    
    int rob(TreeNode* root) {
        robPair* ans = doRobbery(root);
        return max(ans->withrob,ans->withoutrob);
    }
};

int main(){
	TreeNode* root;
	int max_amt_robbed = rob(root);
	cout << max_amt_robbed << "\n";
	return 0;
}
