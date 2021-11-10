#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};

struct node* newNode(int node_data);
struct node* insert_node(struct node* head, int node_data);
void display(struct node* ptr);

struct node* reverseList(struct node* ptr){
	if(ptr == NULL || ptr->next == NULL) return ptr;
	struct node* qtr = reverseList(ptr->next);
	ptr->next->next = ptr;
	ptr->next = NULL;
	return qtr;
}



int main(){
	int n,x;
	cin>>n;
	struct node* head = NULL;
	for(int i=0;i<n;i++){
		cin>>x;
		head = insert_node(head,x);
	}
	cout<<"List[] = ";
	display(head);
	head = reverseList(head);
	cout<<"List[] = ";
	display(head);
	return 0;
}































void display(struct node* ptr){
	if(ptr == NULL){
		cout<<endl;
		return;
	} 
	cout<<ptr->data<<" ";
	display(ptr->next);
}

struct node* insert_node(struct node* head, int node_data){
	struct node* new_node = newNode(node_data);
	if(!head){
		head = new_node;
		return head;
	}
	struct node* ptr = head;
	while(ptr->next) ptr = ptr->next;
	ptr->next = new_node;
	return head;
}

struct node* newNode(int node_data){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = node_data;
	new_node->next = NULL;
	return new_node;
}
