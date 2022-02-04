#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val){
            val = _val;
            next = NULL;
            random = NULL;
        }
}; 

void display(Node* head);

Node* copyRandomList(Node* head) {
    Node* ptr = head;
    
    //making copy of each node
	while(ptr != NULL){
		Node* temp = ptr->next;
		
		Node* copy = new Node(ptr->val);
		ptr->next = copy;
		copy->next = temp;
		
		ptr = temp;
	}	
	
	// assigning random pointer to cloned list
	ptr = head;
	while(ptr != NULL){
		if(ptr->random != NULL){
			ptr->next->random = ptr->random->next;
		}
		ptr = ptr->next->next;
	}
	
	// restoring original list
	ptr = head;
	Node* psuedoHead = new Node(0);
	Node* copy = psuedoHead;
	while(ptr != NULL){
		Node* temp = ptr->next->next;
		
		copy->next = ptr->next;
		ptr->next = temp;
		
		copy = copy->next;
		ptr = front;
	}
	
	
	return psuedoHead->next;
}

int main(){
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = NULL;

    head->random = NULL;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;
    
    //display(head);
    cout << "Hi\n";
    Node* cloned_head = copyRandomList(head);
    display(cloned_head);
        
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
