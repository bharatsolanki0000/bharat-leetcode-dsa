/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* sortedList(ListNode* first, ListNode*second ){

        if(!first){
            return second;
        }
        if(!second){
            return first;
        }
      
            if(first->val < second->val){
                first->next=sortedList(first->next, second);
                return first;
            }
            else{
               second->next=sortedList(first, second->next);
               return second;
            }
        
    }
public:
    ListNode* sortList(ListNode* head) {

        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* slow=head, *fast=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* second=slow->next;
        slow->next=nullptr;
        ListNode* first=head;

        // got two list now rec
        first=sortList(first);
        second=sortList(second);

        
        ListNode* temp=sortedList(first, second);
        return temp;
    }
};