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

    bool solve(TreeNode* root, long long mini,long long maxi){

        if(root==nullptr){
            return true;
        }

        bool leftSide=solve(root->left,mini,root->val);
        bool rightSide=solve(root->right, root->val,maxi);

        bool condition=(root->val >mini && root->val< maxi);

        if(leftSide && rightSide && condition){
            return true;
        }

        return false;
    }
public:
    bool isValidBST(TreeNode* root) {

        if(!root->left && !root->right){
            return true;
        }
        return solve(root,LLONG_MIN,LLONG_MAX);
    }
};