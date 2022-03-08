class Solution {
public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
            ListNode* psuedo_head = new ListNode(0);
            ListNode* curr = psuedo_head;
            
            while(list1 != NULL && list2!=NULL){
                if(list1->val < list2->val){
                    curr->next = list1;
                    list1 = list1->next;
                }
                else{
                    curr->next = list2;
                    list2 = list2->next;
                }
                curr = curr->next;
            }
            
            while(list1 != NULL){
                curr->next = list1;
                list1 = list1->next;
                curr = curr->next;
            }
            
            while(list2 != NULL){
                curr->next = list2;
                list2 = list2->next;
                curr = curr->next;
            }
            return psuedo_head->next;
        }
};

