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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=new ListNode(0);
        ListNode* ans=head;

        if(!list1){
            return list2;
        }

        if(!list2){
            return list1;
        }
     

        while(list1 || list2){

            int first=INT_MAX;
            if(list1){
                first=list1->val;
            }

            int second=INT_MAX;
            if(list2){
                second=list2->val;
            }

            if(first<second){
                head->next=list1;
                list1=list1->next;
            }
            else{
                head->next=list2;
                list2=list2->next;
            }

            head=head->next;
        }
        return ans->next;
    }
};