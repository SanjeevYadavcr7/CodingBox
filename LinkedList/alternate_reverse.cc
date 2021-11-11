#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
	Node(int node_data){
		data = node_data;
		next = NULL;
	}
};

void display(struct Node* node);
int getListLength(struct Node* node);
struct Node* insertNode(struct Node* head, int node_data);
struct Node* reverseList(struct Node* head);

struct Node* rearrange(struct Node* head, int len){	
	struct Node* ptr = head;	
	struct Node* temp;
	int cnt = len/2;
	
	struct Node* tail = head;
	while(tail->next) tail = tail->next; 
	
	while(cnt>0){
		int node_data = head->next->data;
		struct Node* new_node = new Node(node_data);
		head->next = head->next->next;
		tail->next = new_node;
		tail = new_node;
		head = head->next;	
		cnt--;
	}
	temp = ptr;
	cnt = len-len/2;
	while(cnt>1){
		temp = temp->next;
		cnt--;
	} 
	temp->next = reverseList(temp->next);
	return ptr;
}

int main(){
	int n,x;
	cin>>n;
	struct Node* head = NULL;
	for(int i=0;i<n;i++){
		cin>>x;
		head = insertNode(head, x);
	}
	head = rearrange(head,n);
	display(head);
	return 0;
}































struct Node* insertNode(struct Node* head, int node_data){
	struct Node* new_node = new Node(node_data);
	if(head == NULL){
		head = new_node;
		return head;
	}
	struct Node* ptr = head;
	while(ptr->next) ptr = ptr->next;
	ptr->next = new_node;
	return head;
}

void display(struct Node* node){
	if(node == NULL){
		cout<<endl;
		return;
	}
	cout<<node->data<<" ";
	display(node->next);
}

int getListLength(struct Node* node){
	if(node == NULL) return 0;
	return getListLength(node->next)+1;
}

struct Node* reverseList(struct Node* ptr){
	if(!ptr->next) return ptr;
	
	struct Node* qtr = reverseList(ptr->next);
	ptr->next->next = ptr;
	ptr->next = NULL;
	return qtr;
}
















