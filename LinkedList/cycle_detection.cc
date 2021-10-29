#include<iostream>
using namespace std;

class SingleNode{
	public: 
		int data;
		SingleNode* next;
		
		SingleNode(int node_data){
			this->data = node_data;
			this->next = NULL;
		}		
};

class LinkedList{
	public:
		SingleNode* head;
		singleNode* tail;
		
		LinkedList(){
			this->head = NULL;
			this->tail = NULL;
		}
		
		void insert_node(int node_data){
			SingleNode* temp = new SingleNode(node_data);
			if(!this->head) this->head = temp;
			else this->tail->next = temp;
			this->tail = temp;	
		}
};

int findMergeNode(SingleNode* head1, SingleNode* head2) {	
	int ans = 1;
	SingleNode* temp = head1;
	while(temp != NULL){
		temp->data = -1*(temp->data+1);
		temp = temp->next;
	}
	temp = head2;
	while(temp != NULL){
		if(temp->data < 0){
			ans = -1*temp->data-1;
			break;
		}
		temp = temp->next;
	}
	return ans;
}

bool has_cycle(SingleNode* head){
	if(head == NULL) return false;
	SingleNode* slow = head;
	SingleNode* fast = head->next;
	while(slow->next && fast->next){
		if(slow == fast) return true;
		slow = slow->next;
		fast = fast->next->next;
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		LinkedList* list = new LinkedList();
		int n;
		cin>>t;
		for(int i=0;i<n;i++){
			int node_data;
			cin>>node_data;
			list->insert_node(node_data);
		}
		if(has_cycle(list->head)) cout<<"cyclic\n";
		else cout<<"non-cyclic\n";
	}
	
	return 0;
}
