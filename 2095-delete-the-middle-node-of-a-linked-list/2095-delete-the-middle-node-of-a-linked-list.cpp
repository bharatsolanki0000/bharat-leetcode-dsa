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
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr){
                    return nullptr;
                }
                
        if(head->next==nullptr){
            return nullptr;
        }

        

        ListNode* fast=head, *slow=head, *temp;

        while(fast && fast->next){
            temp=slow;
            fast=fast->next->next;
            slow=slow->next;
        }

        
        if(slow->next){
            temp->next=slow->next;
        }
        else{
            temp->next=nullptr;
        }

        return head;
    }
};