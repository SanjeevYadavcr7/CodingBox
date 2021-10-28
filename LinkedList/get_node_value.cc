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

int getSize(SingleNode* head){
	int cnt = 0;
	while(head){
		cnt++;
		head = head->next;
	}
	return cnt;
}

int getNode(SingleNode* head, int pos) {
	if(pos == 0) return head->data;
	int val = getNode(head->next, pos-1);
	return val;
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
		cin>>pos;
		int loc = getSize(list1->head) - pos - 1;
		cout<<getNode(list1->head, loc)<<endl;
		
	}
	return 0;
}
