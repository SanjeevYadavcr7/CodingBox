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

SingleNode* mergeLists(SingleNode* head1, SingleNode* head2){
	LinkedList* list = new LinkedList();
	while(head1 && head2){
		if(head1->data <= head2->data){
			list->insert_node(head1->data);
			head1 = head1->next;
		}
		else{
			list->insert_node(head2->data);
			head2 = head2->next;
		}
	}
	
	while(head1){
			list->insert_node(head1->data);
			head1 = head1->next;
	}
	while(head2){
			list->insert_node(head2->data);
			head1 = head2->next;
	}
	return list=->head;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		LinkedList* list1 = new LinkedList();
		int cnt,x;
		cin>>cnt;
		for(int i=0;i<n;i++){
			cin>>x;
			list1->insert_node(x);
		}
		
		LinkedList* list2 = new LinkedList();
		cin>>cnt;
		for(int i=0;i<n;i++){
			cin>>x;
			list2->insert_node(x);
		}
		cout<<"\nList1[] = ";
		display(head1);
		cout<<"\nList2[] = ";
		display(head2);
		SingleNode* head = mergeLists(list1->head, list2->head);
		cout<<"Merged List[] = ";
		display(head);
	}
	return 0;
}
