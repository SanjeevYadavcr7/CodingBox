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

void display(Node* head);

class LinkedList{
	public: 
		Node* head;
		Node* tail;
		int size = 0;
		
		LinkedList(){
			head = NULL;
			tail = NULL;
		}
		
		void insert_node(int node_data){
			Node* new_node = new Node(node_data);
			if(!head) head = new_node;
			else tail->next = new_node;
			tail = new_node;
			size += 1;
		}
		
		int getFirst(){
			if(!head) return -1;
			else return head->data;
		}
		
		void addFirst(int node_data){
			Node* new_node = new Node(node_data);
			new_node->next = head;
			head = new_node;
			size += 1;
		}
		
		void addLast(int node_data){
			Node* new_node = new Node(node_data);
			tail->next = new_node;
			tail = new_node;
			size += 1;
		}
		
		void removeFirst(){
			if(!head) return;
			else head = head->next;
			size -= 1;
		}
};

void reverseInGroup(int k, LinkedList* list){
			LinkedList *prev = NULL;
			cout<<"Done...2";
			while(list->size > 0){
				
				cout<<"Done...2";
				
				LinkedList* curr = new LinkedList();
				if(list->size >= k){
					for(int i=0;i<k;i++){
						int val = list->getFirst();
						list->removeFirst();
						curr->addFirst(val);
					}
				}
				else{
					int left_size = list->size;
					for(int i=0;i<left_size;i++){
						int val = list->getFirst();
						list->removeFirst();
						curr->addLast(val);	
					}
				}
				cout<<"Done...3";
				if(prev == NULL) prev = curr;
				else{
					prev->tail->next = curr->head;
					prev->tail = curr->tail;
					prev->size += curr->size;
				}	
			}
			list->head = prev->head;
			list->tail = prev->tail;
			list->size = prev->size;
}


int main(){
	int n,k,x;
	cin>>n;
	LinkedList* list = new LinkedList();
	for(int i=0;i<n;i++){
		cin>>x;
		list->insert_node(x);
	}
	Node* new_head = list->head;
	display(new_head);
	cin>>k;		
	reverseInGroup(k, list);
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

