#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};

struct node* NewNode(int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void display(struct node* head){
	if(head == NULL){
		cout<<endl;
		return;
	} 
	cout<<head->data<<" ";
	display(head->next);
}

struct node* reverseList(struct node* head){
	struct node *prev=NULL, *curr=head, *newnext;
	while(curr != NULL){
		newnext = curr->next;
		curr->next = prev;
		prev = curr;
		curr = newnext;
	}
	return prev;
}

int main(){
	struct node* head = NewNode(1);
	head->next = NewNode(7);
	head->next->next = NewNode(9);
	head->next->next->next = NewNode(4);
	head->next->next->next->next = NewNode(5);
	
	display(head);
	head = reverseList(head);
	display(head);
	
	return 0;
}
