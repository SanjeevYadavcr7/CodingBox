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
void display(TreeNode* root);

void preOrderSerialize(TreeNode* node, string& hash){
	if(!node){
		hash += "null ";
		return;
	}
	
	hash += to_string(node->val) + " ";
	preOrderSerialize(node->left,hash);
	preOrderSerialize(node->right,hash);
}

string serialize(TreeNode* root){
	string hash = "";
	preOrderSerialize(root,hash);
	return hash;		
}

TreeNode* constructTree(vector<int>& preOrder){
	int idx = 1;
	stack<pair<TreeNode*,int>> stk;
	TreeNode* root = new TreeNode(preOrder[0]);
	stk.push({root,0});
	
	while(!stk.empty()){
		int state = stk.top().second;
		if(state == 0){
			stk.top().second++;
			if(preOrder[idx] != -1){
				TreeNode* new_node = new TreeNode(preOrder[idx]);
				stk.top().first->left = new_node;
				stk.push({new_node,0});
			}
			idx++;
		}
		else if(state == 1){
			stk.top().second++;
			if(preOrder[idx] != -1){
				TreeNode* new_node = new TreeNode(preOrder[idx]);
				stk.top().first->right = new_node;
				stk.push({new_node,0});
			}		
			idx++;
		}
		else stk.pop();
		
	}
	return root;
}

TreeNode* deserialize(string data){
	int n = data.size();
	vector<int> preOrder;
	
	for(int i=0; i<n; i++){
		string word = "";
		while(i<n && data[i] != ' ') word += data[i++];
		if(word == "null") preOrder.push_back(-1);
		else preOrder.push_back(stoi(word));
	}
	
	TreeNode* root = constructTree(preOrder);
	return root;
}


int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	
	display(root); cout<<"\n";
	
	string hash = serialize(root);
	root = deserialize(hash);
	
	display(root); cout<<"\n";
	
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
