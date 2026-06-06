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

    ListNode* rev(ListNode*head){
        if(!head || !head->next){
            return head;
        }

        ListNode* last=rev(head->next);
        head->next->next=head;
        head->next=nullptr;
        return last;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp=head;

        for(int i=1;i<k;i++){

            if(temp==nullptr){
                return head;
            }

            temp=temp->next;
        }

        if(temp==nullptr){
            return head;
        }

        ListNode* newStartNode=temp->next;

        temp->next=nullptr;

        ListNode* revNode=rev(head);

        head->next=reverseKGroup(newStartNode, k);
        return revNode;

    }
};