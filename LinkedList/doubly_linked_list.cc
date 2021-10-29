#include<iostream>
using namespace std;

class DoublyLinkedListNode{
	public:
		int data;
		DoublyLinkedListNode* next;
		DoublyLinkedListNode* prev;
		
		DoublyLinkedListNode(int node_data){
			this->data = node_data;
			this->next = NULL;
			this->prev = NULL;
		}
};

class DoublyLinkedList{
	public:
		DoublyLinkedListNode* head;
		DoublyLinkedListNode* tail;
		
		DoublyLinkedListNode(){
			this->head = NULL;
			this->tail = NULL;
		}
		
		void insert_node(int node_data){
			DoublyLinkedListNode* temp = new DoublyLinkedListNode(node_data);
			(!this->head) this->head = temp;
			else{
				this->tail->next = temp;
				temp->prev = tail;
			} 
			this->tail = temp;
		}
};


DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
	DoublyLinkedListNode* temp = new DoublyLinkedListNode(data);
	if(head->data > data){
		temp->next = head;
		head->prev = temp;
		head = temp;
		return head;
	}
	DoublyLinkedListNode* ptr = head;
	DoublyLinkedListNode* last_node;
	int swapped = false;
	while(ptr != NULL){
		if(ptr->data > data){
			swapped = true;
			temp->prev = ptr->prev;
			ptr->prev->next = temp;
			ptr->prev = temp;
			temp->next = ptr;
		}
		last_node = ptr;
		ptr = ptr->next;
	}
	if(!swapped) temp->prev = last_node;
	return head;
}

int main(){

		
	return 0;
}
