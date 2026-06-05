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
    ListNode* oddEvenList(ListNode* head) {

        if(head==nullptr){
            return nullptr;
        }

        if(head->next==nullptr){
            return head;
        }


        
        ListNode* even, *odd, *temp;

        even=new ListNode(-1);
        odd=new ListNode(-1);

        ListNode* startEven=even,*startOdd=odd;

        temp=head;
        bool swap=true;

        while(temp){

            if(swap){
                //first is odd
                odd->next=temp;
                odd=odd->next;
            }
            else{
                even->next=temp;
                even=even->next;

            }

            swap=!swap;
            ListNode* tempp=temp->next;
            temp->next=nullptr;
            temp=tempp;

        }

        odd->next=startEven->next;
        return startOdd->next;

        
    }
};