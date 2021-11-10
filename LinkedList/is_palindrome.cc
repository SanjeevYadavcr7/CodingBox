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



int main(){
	int n,x;
	cin>>n;
	struct node* head = NULL;
	for(int i=0;i<n;i++){
		cin>>x;
		head = insert_node(head,x);
	}
	if(isPalindrome(head, head)) cout<<"true\n";
	else cout<<"false\n";
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
