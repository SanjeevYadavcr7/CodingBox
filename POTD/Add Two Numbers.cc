#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void display(ListNode* node);

// Iterative approach: Time: O(N) | Space: O(1)

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* psuedoHead = new ListNode(-1);
        ListNode* curr = psuedoHead;
        int carry = 0, sum = 0;
        
        while(l1 || l2  || carry != 0){
            sum = carry;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum/10;
            sum %= 10;
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        return psuedoHead->next;
}

/*
// Recursive approach: Time: O(N) | Space: O(N)

ListNode* addingNums(ListNode* l1, ListNode* l2, int carry){
	int a = 0, b = 0;
	if(!l1 && !l2 && carry == 0) return NULL;
	if(l1 != NULL) a = l1->val;
	if(l2 != NULL) b = l2->val;
	
	int digit = a+b+carry;
	carry = digit/10;
	digit %= 10;
	
	ListNode* head = new ListNode(digit);
	head->next = addingNums((l1) ? l1->next : NULL,(l2) ? l2->next : NULL,carry);
	return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
	int carry = 0;
	ListNode* head = addingNums(l1,l2,carry);
	return head;
}

*/
int main(){
	ListNode* root1 = new ListNode(9);
	root1->next = new ListNode(9);
	root1->next->next = new ListNode(9);
	root1->next->next->next = new ListNode(9);
	root1->next->next->next->next = new ListNode(9);
	root1->next->next->next->next->next = new ListNode(9);
	root1->next->next->next->next->next->next = new ListNode(9);
	
	ListNode* root2 = new ListNode(9);
	root2->next = new ListNode(9);
	root2->next->next = new ListNode(9);
	root2->next->next->next = new ListNode(9);
	
	cout << "List1 = ";display(root1); cout << "\n";
	cout << "List2 = ";display(root2); cout << "\n";
	
	ListNode* root3 = addTwoNumbers(root1,root2);
	cout << "List3 = ";display(root3); cout << "\n";
	
	return 0;
}




















void display(ListNode* node){
	if(!node) return;
	cout << node->val << " ";
	display(node->next);
}

