#include<bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node* next;
	Node* random;
	Node(int val){
		this->val = val;
		this->next = NULL;
		this->random = NULL;
	}
};
void display(Node* node);


Node* copyRandomList(Node* head){
	if(!head) return NULL;
	
	Node* curr = head;
	
	// STEP 1: Creating deep copy nodes
	while(curr){
		Node* temp = new Node(curr->val);
		Node* temp_next = curr->next;
		curr->next = temp;
		temp->next = temp_next;
		
		curr = temp_next;
	}
	
	// STEP 2: assigning random pointers to deep nodes
	curr = head;
	while(curr){	
		curr->next->random = (curr->random) ? curr->random->next : NULL;
		curr = curr->next->next;	
	}
	
	// resetting next pointers in original list
	Node* psuedoHead = new Node(-1);
	Node* deep = psuedoHead; 
	curr = head;
	while(curr){
		Node* original_next = curr->next->next;
		deep->next = curr->next;
		curr->next = original_next;
		
		curr = curr->next;
		deep = deep->next;
	}
	
	return psuedoHead->next;
}


int main(){
	Node* head = new Node(7);
	head->next = new Node(13);
	head->next->next = new Node(11);
	head->next->next->next = new Node(10);
	head->next->next->next->next = new Node(1);
	
	head->random = NULL;
	head->next->random = head;
	head->next->next->random = head->next->next->next->next;
	head->next->next->next->random = head->next->next;
	head->next->next->next->next->random = head;
	
	display(head);
	Node* new_head = copyRandomList(head);
	display(new_head);


	return 0;
}

















void display(Node* node){
	if(!node){
		cout << "\n";
		return;
	}
	cout << node->val << " ";
	display(node->next);
}
