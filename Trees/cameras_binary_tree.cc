#include<bits/stdc++.h>
using namespace std;

class TreeNode{
	public:
		int val = 0;
		TreeNode* left = NULL;
		TreeNode* right = NULL;
		TreeNode(int val){
			this->val = val;
		}
};
void display(TreeNode* node);
TreeNode* createTree(vector<int>& arr, int idx);

int cameras = 0;

int getMinCamera(TreeNode* node){
	if(node == NULL) return 1;

	int leftChildStatus = getMinCamera(node->left);
	int rightChildStatus = getMinCamera(node->right);

	// children need camera
	if(leftChildStatus == -1 || rightChildStatus == -1){
		cameras++;
		return 0;
	}

	// someone is already covering me
	if(leftChildStatus == 0 || rightChildStatus == 0) return 1;

	// I need camera
	return -1;
}

int minCameraCover(TreeNode* root){
	if(getMinCamera(root) == -1) cameras++;
	return cameras;
}

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	
	TreeNode* root = createTree(arr,0);
	display(root);
	
	return 0;
}






































void display(TreeNode* node){
	if(!node) return;
	
	display(node->left);
	cout << node->val << " ";
	display(node->right);
}

TreeNode* createTree(vector<int>& arr, int idx){
	if(idx == arr.size() || arr[idx] == -1){
		idx++;
		return NULL;
	} 
	TreeNode* node = new TreeNode(arr[idx++]);
	node->left = createTree(arr,idx);
	node->right = createTree(arr,idx);
	return node;
}
