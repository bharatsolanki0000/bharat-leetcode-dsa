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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* temp=head, *prev=nullptr;

        if(head==nullptr){
            return nullptr;
        }

        if(head->next==nullptr){
            return head;
        }


        while(temp){

            bool gotDupli=false;
            while(temp->next && temp->val==temp->next->val){
                gotDupli=true;
                temp=temp->next;
            }


            if(gotDupli){
                temp=temp->next;
                continue;
            }

            if(prev==nullptr){
                head=temp;
                prev=temp;
            }
            else{
                prev->next=temp;
                prev=prev->next;
            }
            temp=temp->next;

        }

        if(prev==nullptr){
            return nullptr;
        }

        prev->next=nullptr;
        return head;
        
    }
};