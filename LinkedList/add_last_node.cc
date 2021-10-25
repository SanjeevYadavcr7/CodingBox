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

struct node* insert(struct node* head, int data){
	struct node* temp = newNode(data);
	if(head == NULL){
		head = temp;
		return temp;
	}
	struct node* ptr = head;
	while(ptr->next != NULL) ptr = ptr->next;
	ptr->next = temp;
	return head;
}

int main(){
	struct node* head = NULL;
	string str;
	getline(cin, str);
	while(str != "q"){
		string temp_n = str.substr(8,2);
		int n = stoi(temp_n);
		head = insert(head,n);
		display(head);
		getline(cin, str);
	}
	return 0;
}
