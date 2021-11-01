#include<iostream>
using namespace std;


class Node{
	public: 
		int data;
		Node* next;
		
		Node(int node_data){
			this->data = node_data;
			this->next = NULL;
		}
};

int countEven(Node* head);
void display(Node* head);

class LinkedList{
	public: 
		Node* head;
		Node* tail;
		
		LinkedList(){
			this->head = NULL;
			this->tail = NULL;
		}
		
		void insert_node(int node_data){
			Node* new_node = new Node(node_data);
			if(!this->head) this->head = new_node;
			else this->tail->next = new_node;
			this->tail = new_node;
		}
		
		void addFirst(int node_data){
			Node* new_node = new Node(node_data);
			new_node->next = this->head;
			this->head = new_node;
		}
		
		void addLast(int node_data){
			Node* new_node = new Node(node_data);
			this->tail->next = new_node;
			this->tail = new_node;
		}
		
		void rearrangeOddEven(){
			if(this->head == NULL) return;
			int cntEven = countEven(this->head);
			if(cntEven == 0) return;
			int cnt = 0;
			Node *ptr = this->head, *prev = NULL;
			while(cnt != cntEven && ptr != NULL){
				if(ptr->data & 1){
					prev = ptr;
					ptr = ptr->next;
					
				}
				else{
					Node* new_node = new Node(ptr->data);
					this->tail->next = new_node;
					this->tail = new_node;
					if(ptr == this->head){
						this->head = this->head->next;
						ptr = this->head;	
					}
					else{
						prev->next = ptr->next;
						ptr = prev->next;
					} 
					cnt++;
				}
			}
		}
};


int main(){
	int n;
	cin>>n;
	LinkedList* list = new LinkedList();
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		list->insert_node(x);
	}
	display(list->head);		
	list->rearrangeOddEven();
	display(list->head);
	cin>>n;
	list->addFirst(n);
	cin>>n;
	list->addLast(n);
	display(list->head);
	
	return 0;
}





void display(Node* head){
	if(head == NULL){
		cout<<endl;
		return;
	}
	cout<<head->data<<" ";
	display(head->next);
}

int countEven(Node* head){
	if(head == NULL) return 0;
	if(head->data & 1) return countEven(head->next);
	else return 1+countEven(head->next);
}
