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

        if(!head || !head->next){
            return head;
        }

        if(k==0){
            return head;
        }

        
        
        int count=1;
        ListNode* temp=head;
        while(temp->next){
            count++;
            temp=temp->next;
        }

        if(k==count){
            return head;
        }

        temp->next=head;

        temp=head;
        int rotate=k%count;

        int skipNodes=count-rotate;
        while(skipNodes--){
            head=temp;
            temp=temp->next;
        }

        head->next=nullptr;
        return temp;

    }
};