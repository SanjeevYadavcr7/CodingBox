#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};

struct node* newNode(int x){
	struct node* temp = (struct node*)malloc(sizeof(struct node)); 
	temp->data = x;
	temp->next = NULL;
	return temp;
}

void displayList(struct node* ptr){
	if(ptr == NULL){
		cout<<"\n";
		return;
	} 
	cout<<ptr->data;
	if(ptr->next != NULL) cout<<" -> ";	
	displayList(ptr->next);
}

int sumList(struct node* ptr){
	int sum = 0;
	if(ptr == NULL) return 0;
	sum = ptr->data + sumList(ptr->next);
	return sum;
}

bool searchNode(struct node* ptr, int x){
	if(ptr == NULL) return false;
	if(ptr->data == x) return true;
	return searchNode(ptr->next, x);
}

struct node* deleteLastNode(struct node* ptr){
	if(ptr->next == NULL){
		free(ptr);
		return NULL;
	}
	ptr->next = deleteLastNode(ptr->next);
	return ptr;
}

struct node* insertNode(struct node* head, int x){
	struct node* temp = newNode(x); 
	if(head == NULL){
		head = temp;
		return head;
	}
	struct node* ptr = head;
	while(ptr->next != NULL) ptr = ptr->next;
	ptr->next = temp;
	return head;
}


struct node* reverseList(struct node* ptr){
	struct node* qtr;
	if(ptr->next == NULL) return ptr;
	
	qtr = reverseList(ptr->next);
	ptr->next->next = ptr;
	ptr->next = NULL;
	return qtr;
}


int main(){
	int n,x;
	cin >> n;
	struct node* head = NULL;
	while(n--){
		cin >> x;
		head = insertNode(head,x);
	}
	displayList(head);
	
	int sum = sumList(head);
	cout<<"Sum = "<<sum<<"\n";
	
	cout<<"Enter item to be searched = ";
	cin >> x;
	if(searchNode(head, x)) cout<<"Item is in here!";
	else cout<<"Item isn't in here!";		
	cout<<"\n";
	
	cout<<"\nNOTE: Deleting last element!\n";
	head = deleteLastNode(head);
	displayList(head);
	
	cout<<"\nCalling ReverseList()....\n";
	head = reverseList(head);
	displayList(head);
		
	return 0;
}
