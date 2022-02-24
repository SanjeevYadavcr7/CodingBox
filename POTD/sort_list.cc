#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void display(ListNode* node);
ListNode* getMidNode(ListNode* head);

ListNode* merge(ListNode* left, ListNode* right){
	ListNode* new_head = new ListNode(0);
	ListNode* curr = new_head;
	
	while(left && right){
		if(left->val <= right->val){
			curr->next = left;
			left = left->next;
		}
		else{
			curr->next = right;
			right = right->next;
		}
		curr = curr->next;
	}
	
	if(left){
		curr->next = left;
		left = left->next;
	}
	
	if(right){
		curr->next = right;
		right = right->next;
	}
	
	return new_head->next;
}

ListNode* sortList(ListNode* node){
	if(!node || !node->next) return node;
	
	ListNode* left = node;
	ListNode* right = getMidNode(node);
	ListNode* temp = right->next;
	right->next = NULL;
	right = temp;
	
	left = sortList(left);
	right = sortList(right);
	return merge(left,right);
}

int main(){
	ListNode* head = new ListNode(4);
	head->next = new ListNode(2);
	head->next->next = new ListNode(1);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(5);

	display(head);
	head = sortList(head);
	display(head);
	
	return 0;
}





























ListNode* getMidNode(ListNode* head){
	ListNode *slow = head, *fast = head;
	while(fast->next && fast->next->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
} 	

void display(ListNode* node){
	if(!node){
		cout << "\n";
		return;
	} 
	cout << node->val << " ";
	display(node->next);
}
