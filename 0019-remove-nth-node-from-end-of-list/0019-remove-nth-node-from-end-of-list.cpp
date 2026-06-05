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

    ListNode* myApproach(ListNode* head, int n){
        
        if(head->next==nullptr ){
           return nullptr;
        }

        if(head->next->next==nullptr){
            //2 nodes

            if(n==1){
                head->next=nullptr;
                return head;
            }

            if(n==2){
                head=head->next;
                return head;
            }
        }

        ListNode* first=head,*second=head;

        int count=0;
        while(first && count<n){
            first=first->next;
            count++;
        }

        if(first==nullptr){
            head=head->next;
            return head;
        }

        while(first->next){
            second=second->next;
            first=first->next;
        }

        if(second->next==first){
            second->next=nullptr;
            return head;
        }

        ListNode* tempp=second->next->next;
        second->next=nullptr;
        second->next=tempp;
        return head;

    }

     ListNode* solve(ListNode* head, int n) {
        
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* first=dummy, *second=dummy;

        for(int i=0;i<=n;i++){
            first=first->next;
        }

        while(first){
            second=second->next;
            first=first->next;
        }

        ListNode* temp=second->next->next;

        second->next=nullptr;
        second->next=temp;

        return dummy->next;
     
     }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {


        //return myApproach;

        return solve(head, n);
    }
};