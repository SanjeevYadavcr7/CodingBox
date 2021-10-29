#include<iostream>
using namespace std;

class SingleNode{
	public:
		int data;
		SingleNode* next;
		
		SingleNode(int node_data){
			this->data = node_data;
			this->next = nullptr;
		}
};

class LinkedList{
	public: 
		SingleNode *head;
		SingleNode *tail;
		
		LinkedList(){
			this->head = nullptr;
			this->tail = nullptr;
		}
		
		void insert_node(int data){
			SingleNode* node = new SingleNode(data);
			
			if(!this->head) this->head = node;
			else this->tail->next = node;
			this->tail = node;
		}
};


SingleNode* removeDuplicates(SingleNode* head) {
	if(head == NULL) return NULL;
	SingleNode* ptr = head;
	while(ptr->next != NULL){
		if(ptr->data == ptr->next->data){
			SingleNode* temp = ptr;
			while(ptr->next != NULL && ptr->data == ptr->next->data){
				ptr = ptr->next;
			}
			if(ptr->next == NULL) temp->next = NULL;
			temp->next = ptr->next;
		}
		else ptr = ptr->next;
	}
	return head;
}


void display(SingleNode* node){
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
		LinkedList* list1 = new LinkedList();
		int n, x, pos;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x;
			list1->insert_node(x);
		}
		removeDuplicates(list1->head);
		display(list1->head);	
	}
	return 0;
}
