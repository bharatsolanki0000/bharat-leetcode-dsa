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
    typedef  long long ll;

    bool solve(TreeNode* root, ll mini, ll maxi){

        if(!root){
            return true;
        }


        if(root->val <=mini || root->val >= maxi){
            return false;
        }

        
        bool leftNode=solve(root->left, mini, root->val);
        bool rightNode=solve(root->right, root->val, maxi);

        

        return leftNode && rightNode;

        
    }
public:
    bool isValidBST(TreeNode* root) {
        
        ll mini=LLONG_MIN;
        ll maxi=LLONG_MAX;
        return solve(root, mini,maxi);
    }
};