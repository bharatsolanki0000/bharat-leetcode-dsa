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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(!head->next){
            return nullptr;
        }

        int count=0;
        ListNode* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }

        //if last node
        count=count-n;
        if(count==0){
            return head->next;
        }

        
        temp=head;
        ListNode* ans=temp;
        while(temp){
            count--;
            if(count==0 && temp->next){
                ListNode* temper=temp->next->next;
                temp->next=nullptr;
                temp->next=temper;
                temp=temper;
            }
            else{
                temp=temp->next;
            }

        }
        return ans;

    }
};