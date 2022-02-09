#include<bits/stdc++.h>
using namespace std;

class Node {
	public:
   		int val;
        Node* next;
        Node* random;

        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
};

Node* copyRandomList(Node* head) {
	Node* curr_node = head;
	
	// STEP 1: adding cloned nodes in original list
	while(curr_node){
		Node* next_node = curr_node->next;
		
		Node* copy_node = new Node(curr_node->val);
		curr_node->next = copy_node;
		copy_node->next = next_node;
		
		curr_node = next_node;
	}
	
	// STEP 2: assigning random pointers to cloned nodes
	curr_node = head;
	while(curr_node){
		if(!curr_node->random) curr_node->next->random = NULL;
		curr_node->next->random = curr_node->random->next;
		
		curr_node = curr_node->next->next;
	}
	
	// STEP 3: detatching next pointers from original list
	curr_node = head;
	Node* old_next = curr_node->next->next;
	Node* cloned_head = NULL;
	Node* temp = cloned_head;
	while(curr_node){
		if(curr_node == head){
			cloned_head = curr_node->next;
		} 
		temp->next = old_next->next;
		
		curr_node->next = old_next;
		
		temp = temp->next;
		curr_node = old_next;
		old_next = old_next->next->next;
	}
}

int main(){
	

	return 0;
}
