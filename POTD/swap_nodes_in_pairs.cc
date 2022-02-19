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

ListNode* reverseList(ListNode* node, int k){
	ListNode *prev = NULL, *curr = node, *temp_next;
	int cnt = 0;
	while(curr != NULL && cnt < k){
		temp_next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp_next;
		cnt++;
	}
	if(temp_next) node->next = reverseList(temp_next,k);
	return prev;
}	

ListNode* swapPairs(ListNode* head) {
	return reverseList(head,2);
}

int main(){
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);

	display(head);
	head = swapPairs(head);
	display(head);
	
	return 0;
}





































void display(ListNode* node){
	if(!node){
		cout << endl;
		return;
	} 
	cout << node->val << " ";
	display(node->next);
}	
