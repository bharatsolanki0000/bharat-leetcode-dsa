/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        map<ListNode*,int> mp;

        ListNode* first=headA;
        ListNode* second=headB;

        while(first){
            mp[first]=1;
            first=first->next;
        }

        while(second){

            if(mp.count(second)){
                return second;
            }
            second=second->next;
        }

        return nullptr;
    }
};