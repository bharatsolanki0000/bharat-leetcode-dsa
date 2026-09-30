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

    bool solve(TreeNode* first, TreeNode* second){

        if(first==nullptr && second==nullptr){
            return true;
        }

        if(!first && second || !second && first){
            return false;
        }

        if(first->val !=second->val){
            return false;
        }

        bool leftSide=solve(first->left, second->right);
        bool rightSide=solve(first->right, second->left);


        if(!leftSide || !rightSide){
            return false;
        }

        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root,root);
    }
};