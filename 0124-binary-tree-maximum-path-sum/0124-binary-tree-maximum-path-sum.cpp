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

    int solve(TreeNode* root, int &maxi){

        if(root==nullptr){
            return 0;
        }


        int leftSide=max(0,solve(root->left,maxi));
        int rightSide=max(0,solve(root->right,maxi));

        maxi=max(maxi,root->val+leftSide+rightSide);

        return root->val+max(leftSide,rightSide);
    }
public:
    int maxPathSum(TreeNode* root) {

       
        int maxi=INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};