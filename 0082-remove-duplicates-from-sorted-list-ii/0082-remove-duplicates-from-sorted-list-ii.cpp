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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* prev=new ListNode(-1);
        ListNode* ans=prev;

        ListNode* temp=head;

        while(temp){

            bool gotDupli=false;
            while(temp->next && temp->val== temp->next->val){
                temp=temp->next;
                gotDupli=true;
            }

            if(!gotDupli){
                prev->next=temp;
                prev=prev->next;
            }
            
            temp=temp->next;
        }

        prev->next=nullptr;
        return ans->next;
    }
};