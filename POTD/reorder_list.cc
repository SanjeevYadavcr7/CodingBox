#include<bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(): val(0), next(NULL) {}
	ListNode(int x): val(x), next(NULL) {}
	ListNode(int x, ListNode* next): val(x), next(next) {}
};
void display(ListNode* node);
int getLen(ListNode* head);

ListNode* curr_head;
void reorderListHelper(ListNode* right, int size, int pos){
	if(!right) return;
	reorderListHelper(right->next,size,pos+1);
	
	if(pos > size/2){
		ListNode* next_head = curr_head->next;
		curr_head->next = right;
		right->next = next_head;
		curr_head = next_head;
	}
	else if(pos == size/2){
		right->next = NULL;
	}
}

void reorderList(ListNode* head){
	curr_head = head;
	int size = getLen(head);
	reorderListHelper(head,size,0);
}


int main(){
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	//head->next->next->next->next = new ListNode(5);
	
	display(head);
	reorderList(head);
	cout<<"After Reordering....\n";
	display(head);
	
	return 0;
}







































void display(ListNode* node){
	if(!node){
		cout<<endl;
		return;
	}
	cout<<node->val<<" "; 
	display(node->next);
}

int getLen(ListNode* node){
	if(!node) return 0;
	return getLen(node->next)+1;
}
