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

    int solve(TreeNode* root, int &maxi ){

        if(root==nullptr){
            return 0;
        }

        int leftNode=max(0, solve(root->left, maxi));
        int rightNode=max(0,solve(root->right, maxi));

        maxi=max(maxi,root->val+leftNode+rightNode);
        int sum=root->val+max(leftNode, rightNode);
        return sum;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};