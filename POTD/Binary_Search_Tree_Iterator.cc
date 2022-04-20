#include "utils.h"

/*  Using Linked List  */

struct Node{
	int val;
	Node* next;
	Node(int _val){
		val = _val;
		next = NULL;
	}
};

class BSTIterator {
public:	
	TreeNode* root;
	TreeNode* bstItr;
	TreeNode* minNode;
	Node* inOrderList = new Node(-1);
	Node* ptr = inOrderList;
	
	void getInorderList(TreeNode* node){
		if(!node) return;
		getInorderList(node->left);
		ptr->next = new Node(node->val);
		ptr = ptr->next;
		getInorderList(node->right);
	}	
	
    BSTIterator(TreeNode* head) {
    	root = head;
		getInorderList(root);    	
    }
    
    int next() {
    	inOrderList = inOrderList->next;
    	return inOrderList->val;
    }
    
    bool hasNext() {
		if(inOrderList->next) return true;
		return false;
    }
};

/*---------------------------------------------------------------*/


/* Using Stack


class BSTIterator {
public:		
	stack<TreeNode*> inOrder;
	
    BSTIterator(TreeNode* head) {
		getInorder(head);
    }
    
    int next() {
		TreeNode* curr_node = inOrder.top();
		inOrder.pop();
		
		getInorder(curr_node->right);
		return curr_node->val;
    }
    
    bool hasNext() {
		return !inOrder.empty();
    }
    
    void getInorder(TreeNode* node){
		while(node){
			inOrder.push(node);
			node = node->left;
		}
	}
};
*/

int main(){
	TreeNode* root;
	BSTIterator* obj = new BSTIterator(root);
	/*
	int param_1 = obj->next();
	bool param_2 = obj->hasNext();
 	*/
	return 0;	
}
