/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;

        while(temp){
            Node* newNode=new Node(temp->val);
            Node* newNext=temp->next;
            temp->next=nullptr;
            temp->next=newNode;
            newNode->next=newNext;

            temp=temp->next->next;
        }

        temp=head;
        while(temp){
            Node* newTemp=temp->next;
            if(temp->random){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }

        Node* ans=new Node(-1);
        Node* result=ans;

        temp=head;
        while(temp){
            ans->next=temp->next;
            ans=ans->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return result->next;
    }
};