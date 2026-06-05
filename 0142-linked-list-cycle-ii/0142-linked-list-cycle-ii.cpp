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
    ListNode *detectCycle(ListNode *head) {

        if(head==nullptr){
            return nullptr;
        }
        
        if(head->next==nullptr){
            return nullptr;
        }

        ListNode*slow=head, *fast=head;

        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;

            if(fast==slow){
                break;
            }
        }

        if(fast==nullptr || fast->next==nullptr){
            return nullptr;
        }

        fast=head;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }

        return slow;
    }
};