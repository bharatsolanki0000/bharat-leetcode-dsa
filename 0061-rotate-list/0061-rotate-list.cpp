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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        

        ListNode* front=head;
        int nodes=0;
        while(front!=nullptr){
            nodes++;
            front=front->next;
        }

        k=k%nodes;
        front=head;
        while(front->next!=nullptr && k){
            k--;
            front=front->next;
        }

        ListNode* prev=head;
        while(front->next!=nullptr){
            front=front->next;
            prev=prev->next;
        }

        front->next=head;
        ListNode* ans=prev->next;
        prev->next=nullptr;
        return ans;
    }
};