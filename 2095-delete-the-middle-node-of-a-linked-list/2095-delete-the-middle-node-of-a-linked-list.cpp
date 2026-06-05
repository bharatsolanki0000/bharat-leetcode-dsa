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
        
        //0 node
        if(head==nullptr){
            return nullptr;
        }

        //1 node
        if(head->next==nullptr){
            return nullptr;
        }

        //2 nodes
        if(head->next->next==nullptr){
            head->next=nullptr;
            return head;
        }


        ListNode* slow=head, *fast=head->next->next;

        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* toDelete=slow->next;

        slow->next=slow->next->next;
        delete toDelete;

        return head;
    }
};