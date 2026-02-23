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

        if(head==nullptr || head->next==nullptr){
            return head;
        }

        ListNode* last=rev(head->next);  
        head->next->next=head;
        head->next=nullptr;
        return last;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head==nullptr || head->next==nullptr){
            return head;
        }
        int count=k-1;

        ListNode* startNode=head;

        while(startNode && count>0){
            count--;
            startNode=startNode->next;
        }
        
        if(startNode == nullptr)
            return head;

        ListNode* newHead=startNode->next;
        startNode->next=nullptr;
        ListNode* revNode=rev(head);
        head->next=reverseKGroup(newHead, k);
        head=revNode;
        return head;


    }
};