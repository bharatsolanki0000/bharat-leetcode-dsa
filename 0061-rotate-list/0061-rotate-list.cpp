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
        if(k==0){
            return head;
        }

        if(head==nullptr){
            return nullptr;
        }

        if(head->next==nullptr){
            return head;
        }

        int totalNodes=1;

        ListNode* temp=head;
        while(temp->next){
            temp=temp->next;
            totalNodes++;
        }

        if(totalNodes==k){
            return head;
        }

        //connect end to head
        temp->next=head;


        int rotate=k%totalNodes;

        int newHeadPos=totalNodes-rotate;

        ListNode* prev;
        for(int i=0;i<newHeadPos;i++){
            prev=head;
            head=head->next;
        }

        prev->next=nullptr;
        return head;

    }
};