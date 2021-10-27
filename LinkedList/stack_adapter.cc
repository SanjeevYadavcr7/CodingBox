#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};

struct node* createNode(int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

struct node* push(struct node* head, int data){
	struct node* temp = createNode(data);
	if(head == NULL){
		head = temp;
		return head;
	}
	temp->next = head;
	head = temp;
	return head;
}

struct node* pop(struct node* head){
	if(head == NULL){
		cout<<"Stack underflow\n";
		return head;
	}
	cout<<head->data<<"\n";
	head = head->next;
	return head;
}

int getTop(struct node* head){
	return head->data;
}

int getSize(struct node* head){
	int cnt = 0;
	while(head != NULL){
		head = head->next;
		cnt++;
	}
	return cnt;
}


int main(){
	struct node* head = NULL;
	string str;
	getline(cin, str);
	while(str != "quit"){
		if(str[1] == 'u'){
			string temp = str.substr(5);
			int num = stoi(temp);
			head = push(head,num);
		}
		else if(str == "pop"){
			head = pop(head);
		}
		else if(str == "top"){
			int data = getTop(head);
			cout<<data<<"\n";
		}
		else if(str == "size"){
			int size = getSize(head);
			cout<<size<<"\n";
		}
		getline(cin, str);
	}

	return 0;
}
