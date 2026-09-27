/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    bool check(TreeNode* p, TreeNode* q){
        if(!p && !q){
            return true;
        }

        if(!p && q || !q && p){
            return false;
        }

        if(p->val != q->val){
            return false;
        }

        bool leftSide=check(p->left, q->left);
        bool rightSide=check(p->right, q->right);

        if(!leftSide || !rightSide){
            return false;
        }

        return true;
    }

    bool bfsSolve(TreeNode* p, TreeNode* q){

        queue<pair<TreeNode*,TreeNode*>> qu;
        qu.push({p,q});


        while(!qu.empty()){
            auto top=qu.front();
            TreeNode* first=top.first;
            TreeNode* second=top.second;
            qu.pop();

            if(!first && !second)continue;

            if(!first || !second || first->val!=second->val) return false;

            qu.push({first->left, second->left});
            qu.push({first->right,second->right});
        }
        return true;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //return check(p,q);

        return bfsSolve(p,q);
    }
};