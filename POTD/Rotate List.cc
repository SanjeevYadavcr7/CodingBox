#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void display(ListNode* head);

ListNode* rotateRight(ListNode* head, int k){
	if(!head || !head->next || k == 0) return head;
	
	ListNode* curr = head;
	int len = 0;
	while(curr && ++curr) curr = curr->next;
	
	curr->next = head;
	k %= n;
	k = len-k;
	while(k--) curr = curr->next;
	head = curr->next;
	curr->next = NULL;
	
	return head;
}

/*
int getListLength(ListNode* head){
	int cnt = 0;
	while(head){
		cnt += 1;
		head = head->next;
	}
	return cnt;
}

ListNode* rotateRight(ListNode* head, int k){
	int n = getListLength(head);
	if(!head || k == 0 || k%n == 0) return head;
	
	k %= n;
	
	if(k == 0) return head;
	
	int break_point = n - k;
	ListNode *left, *right = head;;
	ListNode* curr = head;
	while(break_point > 1){
		curr = curr->next;
		break_point--;
	}
	left = curr->next;
	curr->next = NULL;
	curr = left;
	while(curr->next) curr = curr->next;

	curr->next = right;	
	return left;
}
*/

int main(){
	int k;
	cin >> k;
	
	ListNode* head = new ListNode(0);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	//head->next->next->next = new ListNode(4);
	//head->next->next->next->next = new ListNode(5);
	
	display(head);
	head = rotateRight(head,k);
	display(head);
	
	return 0;
}

























void display(ListNode* head){
	while(head){
		cout << head->val << " ";
		head = head->next;
	}
	cout << "\n";
}
