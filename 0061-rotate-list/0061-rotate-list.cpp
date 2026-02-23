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
        
        if(head==nullptr || head->next==nullptr || k==0){
            return head;
        }

        ListNode* temp=head, *last;
        int nodes=0;
        while(temp){
            nodes++;
            last=temp;
            temp=temp->next;
        }

        int rotateTime=k%nodes;

        if(rotateTime==0){
            return head;
        }

        //new head will be at countNode-(k%countNodes)

        last->next=head;
        int newHeadPos=nodes-(rotateTime);
        while(newHeadPos>0){
            last=last->next;
            newHeadPos--;
        }

        ListNode* ans=last->next;
        last->next=nullptr;
        return ans;

    }
};