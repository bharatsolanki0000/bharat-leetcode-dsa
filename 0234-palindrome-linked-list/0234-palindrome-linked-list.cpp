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

    ListNode* rev(ListNode* head){

        if(!head || !head->next){
            return head;
        }

        ListNode* last=rev(head->next);
        head->next->next=head;

        head->next=nullptr;
        return last;
    }
public:
    bool isPalindrome(ListNode* head) {

        if(!head->next){
            return true;
        }
           
        ListNode* fast=head, *slow=head;

        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        } 


        ListNode* newList=slow->next;
        slow->next=nullptr;

        newList=rev(newList);

        ListNode* first=head, *second=newList;

        while(first && second){

            if(first->val !=second->val){
                return false;
            }
            first=first->next;
            second=second->next;
        }

        return true;


    }
};