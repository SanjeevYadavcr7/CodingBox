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
		
		DoublyLinkedList(){
			this->head = NULL;
			this->tail = NULL;
		}
		
		void insert_node(int node_data){
			DoublyLinkedListNode* temp = new DoublyLinkedListNode(node_data);
			if(!this->head) this->head = temp;
			else{
				this->tail->next = temp;
				temp->prev = tail;
			} 
			this->tail = temp;
		}
};

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
	if(head == NULL) return NULL;
	DoublyLinkedListNode *new_prev = NULL, *curr = head, *new_next;
	while(curr != NULL){
		new_next = curr->next;
		curr->next = new_prev;
		curr->prev = new_next;
		new_prev = curr;
		curr = new_next;
	} 
	return new_prev;
}


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

void display(DoublyLinkedListNode* node){
	if(node == NULL){
		cout<<endl;
		return;
	}
	cout<<node->data<<" ";
	display(node->next);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		DoublyLinkedList* list = new DoublyLinkedList();
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			int node_data;
			cin>>node_data;
			list->insert_node(node_data);
		}
		display(list->head);
		list->head = reverse(list->head);
		display(list->head);
	}	
		
	return 0;
}



















