#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};	

void display(struct node* ptr){
	while(ptr != NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

struct node* newNode(int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void findIntersectionPoint(struct node* head1, struct node* head2){

	// if data >= 0	
	while(head1->next != NULL){
		head1->data = -1*(head->data+1);
		head1 = head1->next;
	}
	int flag = 0, ans=-1;
	while(head2->next != NULL){
		if(head2->data < 0){
			flag=1;
			ans = -1*(head->data);
			break;
		}
		head2 = head2->next;
	}
	if(flag) cout<<ans-1<<endl;
	else cout<<ans<<endl;
	return;
}


int main(){
	struct node* head1 = newNode(1);
	head1->next = newNode(2);
	head1->next = newNode(3);
	head1->next = newNode(4);
	head1->next = newNode(5);
	head1->next = newNode(6);
	head1->next = newNode(7);
	
	struct node* head2 = newNode(9);
	head2->next = newNode(8);
	head2->next = newNode(5);
	head2->next = newNode(6);
	head2->next = newNode(7);
	
	findIntersectionPoint(head1, head2);
	
	return 0;
}
