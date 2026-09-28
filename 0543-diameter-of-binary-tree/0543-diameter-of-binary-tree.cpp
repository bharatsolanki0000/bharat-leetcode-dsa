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

    int solve(TreeNode*root){
        if(root==nullptr){
            return 0;
        }

        int leftSide=solve(root->left);
        int rightSide=solve(root->right);

        int total=height(root->left)+height(root->right);

        return max(total,max(leftSide, rightSide));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root);
        
    }
};