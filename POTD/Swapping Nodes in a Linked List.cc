#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* getListHead(vector<int>& arr);
void displayList(ListNode* node);

int len = 0, back = 0;
void goToTail(ListNode* node, ListNode* temp, int cnt, int k){
	if(!node){
		len = cnt-1;
		back = 1;
		return;
	}
	
	if(cnt == k) temp = node;
	goToTail(node->next,temp,cnt+1,k);
	
	cout << "Cnt = " << cnt << "\n";
	
	if(len-cnt+1 == k && back == 1){
		int val = node->val;
		node->val = temp->val;
		temp->val = val;
	}
}

ListNode* swapNodes(ListNode* head, int k){
	int cnt = 1;
	ListNode* val;
	int n = 0;
	ListNode* temp = head;
	while(temp){
		temp = temp->next;
		n++;
	}
	
	k = min(k,n-k+1);
	
	goToTail(head,val,cnt,k);
	return head;
}


int main(){	
	int n,k;
	cin >> n >> k;
	vector<int> list(n);
	for(int i=0; i<n; i++) cin >> list[i];
	
	ListNode* head = getListHead(list);
	displayList(head);
	head = swapNodes(head,k);
	displayList(head);
	
	return 0;
}





///////////////////////////////////////////////////

// Add-ons :)

void displayList(ListNode* node){
	while(node){
		cout << node->val << " ";
		node = node->next;
	}
	cout << "\n";
}

ListNode* getListHead(vector<int>& arr){
	ListNode *head = NULL, *curr;
	for(int &i : arr){
		ListNode* node = new ListNode(i);
		if(!head){
			head = node;
			curr = head;
		}
		else{
			curr->next = node;
			curr = curr->next;
		}
	}
	return head;
} 
