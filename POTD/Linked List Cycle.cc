/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	
	// Most Optimised solution: Time = O(N) | Space = O(1)
	
	bool hasCycle(ListNode *head){
        if(!head || !head->next) return false;
        
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
    
    //------------------------------------------------------- 
    
    // Optimised solution: Time = O(N) | Space = O(1)
    // But modifying list values
    
    bool hasCycle(ListNode *head) {
        ListNode* curr = head;
        while(curr != NULL){
            if(curr->val == INT_MIN) return true;
            curr->val = INT_MIN;
            curr = curr->next;
        }
        return false;
    }
    
    //------------------------------------------------------- 
    
    // Naive approach: Time = O(N) | Space = O(N)
     
    bool hasCycle(ListNode *head) {
    	unordered_map<ListNode*,bool> mp;
    	ListNode* curr = head;
    	while(curr != NULL){
    		if(mp[curr] == true) return true;
    		mp[curr] = true;
    		curr = curr->next;
    	}
    	return false;
    }
};
