#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};

struct node* newNode(int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

int getSize(struct node* ptr){
	int cnt = 0;
	while(ptr != NULL){
		cnt++;
		ptr = ptr->next;
	}
	return cnt;
}

void display(struct node* head){
	if(head == NULL){
		cout<<endl;
		return;
	} 
	cout<<head->data<<" ";
	display(head->next);
}

struct node* insert(struct node* head, int n){
	struct node* temp = newNode(n);
	if(head == NULL){
		head = temp;
		return head;
	}
	struct node* ptr = head;
	while(ptr->next != NULL) ptr = ptr->next;
	ptr->next = temp;
	return head;
}

struct node* removeHead(struct node* head){
	if(head == NULL){
		cout<<"List is empty\n";
		return NULL;
	}
	struct node* temp = head->next;
	head = temp;
	return head;
}

int getFirst(struct node* head){
	if(head == NULL){
		cout<<"List is empty";
		return -1;
	}
	int top = head->data;
	return top;	
}

int getLast(struct node* head){
	if(head == NULL){
		cout<<"List is empty";
		return -1;
	}
	if(head->next == NULL) return head->data;
	return getLast(head->next);
}

int getAt(struct node* head, int loc){
	if(head == NULL){
		cout<<"List is empty";
		return -1;
	}
	int e = -1,i=0;
	while(head != NULL){
		if(i == loc){
			e = head->data;
			break;
		}
		i++;
		head = head->next;
	}
	if(e == -1) cout<<"Invalid arguments";
	return e;
}

struct node* addFirst(struct node* head, int data){
	struct node* temp = newNode(data);
	temp->next = head;
	head = temp;
	return head;	
}

struct node* addAt(struct node* head, int loc, int data){
	
}

int main(){

	struct node* head = NULL;	
	
	string str;
	getline(cin, str);
	while(str != "quit"){
		if(str.substr(0,5) == "addAt"){
			
		}
		else if(str[3] == 'A'){
			string temp = str.substr(6);
			int loc = stoi(temp);
			cout<<getAt(head,loc)<<endl;
		}  
		else if(str[3] == 'F'){
			string temp = str.substr(9);
			int num = stoi(temp);
			head = addFirst(head,num);
		}
		else if(str == "getFirst") cout<<getFirst(head)<<endl;
		else if(str == "getLast") cout<<getLast(head)<<endl;
		else if(str[0] == 'd') display(head);
		else if(str[0] == 'r') head = removeHead(head);
		else if(str[0] == 's') cout<<getSize(head)<<endl;
		else if(str[0] == 'a'){
			string temp = str.substr(8,2);
			int n = stoi(temp);
			head = insert(head, n);
		}
		getline(cin, str);
	}
	
	return 0;
}
