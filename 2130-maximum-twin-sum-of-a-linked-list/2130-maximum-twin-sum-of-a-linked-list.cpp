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

    ListNode*rev(ListNode* head){
        if(!head || !head->next){
            return head;
        }

        ListNode* last=rev(head->next);
        head->next->next=head;
        head->next=nullptr;
        return last;
    }
public:
    int pairSum(ListNode* head) {

        if(head->next->next==nullptr){
            return head->val+ head->next->val;
        }
        
        ListNode* fast=head, *slow=head;

        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* halfListHead=slow->next;
        slow->next=nullptr;

        halfListHead=rev(halfListHead);

        ListNode* first=head,*second=halfListHead;

        
        int maxi=0;
        while(first && second){

            int sum=0;
            sum+=first->val;
            sum+=second->val;

            maxi=max(maxi, sum);

            first=first->next;
            second=second->next;


        }

        return maxi;
    }
};