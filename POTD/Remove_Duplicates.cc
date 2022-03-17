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

/*

// Naive approach - Time: O(N) | Space: O(N)


ListNode* deleteDuplicates(ListNode* head) {
	 map<int,int> mp;
     ListNode* curr = head;

     while(curr){
        mp[curr->val]++;
     	curr = curr->next;
     }

     ListNode *new_head = new ListNode(0);
     curr = new_head;
     for(auto it : mp){
        if(it.second > 1) continue;
        curr->next = new ListNode(it.first);
      	curr = curr->next;
     }
     return new_head->next;
}

*/

ListNode* deleteDuplicates(ListNode* head){
	if(!head || !head->next) return head;
	
	ListNode* psuedoHead = new ListNode(-1,head);
	ListNode* unique = psuedoHead;
	ListNode* curr = head->next;
	
	while(curr){
		bool rep = false;
		while(curr && unique->next->val == curr->val){
			rep = true;
			curr = curr->next;
		}
		
		if(rep) unique->next = curr;
		else unique = unique->next;
		
		if(curr) curr = curr->next; 
	}
	return psuedoHead->next;
}


int main(){
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(4);
	head->next->next->next->next->next = new ListNode(4);
	head->next->next->next->next->next->next = new ListNode(5);

	display(head);
	head = deleteDuplicates(head);
	display(head);

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
