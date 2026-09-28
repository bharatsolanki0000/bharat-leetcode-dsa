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

    int height(TreeNode* root){
        if(root==nullptr){
            return 0;
        }

        int leftSide=height(root->left);
        int rightSide=height(root->right);
        return 1+max(leftSide,rightSide);
    }

    bool solve(TreeNode* root){
        if(root==nullptr){
            return true;
        }

        bool leftSide=solve(root->left);
        bool rightSide=solve(root->right);

        int diff=abs(height(root->left)-height(root->right));

        if(!leftSide || !rightSide || diff>1){
            return false;
        }

        return true;
        
    }
public:
    bool isBalanced(TreeNode* root) {
        return solve(root);
    }
};