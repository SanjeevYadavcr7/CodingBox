#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};

void display(struct node* node){
	if(node == NULL){
		cout<<endl;
		return;
	}
	cout<<node->data<<" ";
	display(node->next);
}

struct node* newNode(int node_data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = node_data;
	temp->next = NULL;
	return temp;
}

struct node* insert_node(struct node* head, int node_data){
	struct node* temp = newNode(node_data);
	if(head == NULL){
		head = temp;
		temp = head;
		return head;
	}
	struct node* ptr = head;
	while(ptr->next) ptr = ptr->next;
	ptr->next = temp;
	return head;
	
}

struct node* remove_duplicates(struct node* head){
	if(head == NULL) return NULL;
	struct node* ptr = head;
	while(ptr->next){
		if(ptr->next && ptr->data == ptr->next->data){
			struct node* temp = ptr;
			while(ptr->next && ptr->data == ptr->next->data){
				ptr = ptr->next;
			}
			if(!ptr->next) temp->next = NULL;
			else temp->next = ptr->next;
		}
		else ptr = ptr->next;
	}
	return head;
}

int main(){
	int n;
	cin>>n;
	struct node* head = NULL;
	for(int i=0;i<n;i++){
		int node_data;
		cin>>node_data;
		head = insert_node(head,node_data);
	}
	display(head);
	head = remove_duplicates(head);
	display(head);
	return 0;
}
