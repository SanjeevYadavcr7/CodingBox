#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void display(ListNode* node);

/*
int pos = -1;
ListNode *detectCycle(ListNode *head){
	if(!head) return NULL;
	
	int i = 1;
	unordered_map<ListNode*,int> mp;
	ListNode* temp = head;
	while(temp){
		if(mp[temp]){
			pos = mp[temp]-1;
			return temp;
		} 
		mp[temp] = i++;
		temp = temp->next;
	}	
	return NULL;
}
*/

ListNode *detectCycle(ListNode *head){
	if(!head) return NULL;
	int i = INT_MAX;
	while(head){
		if(head->val > i){
			head->val = INT_MAX - head->val;
			return head;
		} 
		head->val = i;
		i--;
		head = head->next;
	}
	
	return NULL;
}


int main(){
	int n;
	cin >> n;
	ListNode* head = NULL;
	ListNode* tail = NULL;
	for(int i=0; i<n; i++){
		int node_val;
		cin >> node_val;
		if(!head){
			head = new ListNode(node_val);
			tail = head;
		}
		else{
			tail->next = new ListNode(node_val);
			tail = tail->next;
		}
	}
	// creating cycle
	//tail->next = head->next;
	
	head = detectCycle(head);
	if(head) cout << head->val << "\n";
	else cout<< "-1\n";
	
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
