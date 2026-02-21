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
    ListNode* solve(ListNode* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* last=solve(head->next);
        head->next->next=head;
        head->next=nullptr;
        return last;

    }
public:
    ListNode* reverseList(ListNode* head) {
        return solve(head);
    }
};