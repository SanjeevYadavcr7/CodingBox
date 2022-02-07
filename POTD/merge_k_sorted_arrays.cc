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


int main(){
	ListNode* head1 = new ListNode(1);
	head1->next = new ListNode(4);
	head1->next->next = new ListNode(5);
	
	ListNode* head2 = new ListNode(1);
	head2->next = new ListNode(3);
	head2->next->next = new ListNode(4);
	
	ListNode* head3 = new ListNode(2);
	head3->next = new ListNode(6);

	display(head1);
	display(head2);
	display(head3);

	return 0;
}


























void display(ListNode* node){
	if(!node){
		cout << "\n";
		return;
	} 
	cout << node->val << " ";
	display(node->next);
}
