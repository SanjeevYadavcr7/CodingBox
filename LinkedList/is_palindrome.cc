#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};
struct node* head = NULL;
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

bool isPalindrome(struct node* ptr, struct node* &head){
	if(!ptr->next){
		if(ptr->data == head->data){
			head = head->next;
			return true;
		} 
		else return false;
	}
	
	if(isPalindrome(ptr->next, head)){
		if(ptr->data == head->data){
			head = head->next;
			return true;
		}
		else return false;
	}	
	return false;
}	

int getListLength(struct node* ptr,int len){
	if(ptr == NULL) return len;
	return getListLength(ptr->next,len+1);
}

struct node* left_node;

void foldListHelper(struct node* right, int floor, int size){
	if(right == NULL) return;
	foldListHelper(right->next, floor+1,size);
	if(floor > size/2){
		struct node* temp = left_node->next;
		left_node->next = right;
		right->next = temp;
		left_node = temp;	
	} else if(floor == size/2){
		left_node->next = right;
		right->next = NULL; 
	}
}

struct node* foldList(struct node* head, int size){
	if(!head) return NULL;
	left_node = head;
	foldListHelper(head,0,size);
	return head;
}



int main(){
	int n,x;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>x;
		head = insert_node(head,x);
	}

	head = foldList(head,n);
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
