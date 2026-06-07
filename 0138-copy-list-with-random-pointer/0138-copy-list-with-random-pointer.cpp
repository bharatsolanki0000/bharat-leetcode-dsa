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
        Node*temp=head;

        unordered_map<Node*,Node*> oriToClone;


        //insert original node and copy node into map
        while(temp){
            Node* newNode=new Node(temp->val);
            oriToClone[temp]=newNode;
            temp=temp->next;
        }

        temp=head;

    // connect ori->next for copy->next=node
        while(temp){


            //next of copy will be same as temp->next
            Node* nextCopyNode=oriToClone[temp->next];
            Node* copyNode=oriToClone[temp];

            copyNode->next=nextCopyNode;

            //random of cpy will be same as temp->random
            Node* randomCopyNode=oriToClone[temp->random];

            copyNode->random=randomCopyNode;
            temp=temp->next;

        }

        return oriToClone[head];


    }
};