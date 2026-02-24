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

    void solve(TreeNode* root, int &ans, int bits){

        if(root==nullptr){
            return ;
        }

        
        if(root->left==nullptr && root->right==nullptr){
            ans+=bits;
            return ;
        }
        

        if(root->left){
            solve(root->left, ans, bits*2+root->left->val);
        }
        if(root->right){
            solve(root->right,ans, bits*2+root->right->val);
        } 
        

    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans=0;
        int bits=root->val;
        solve(root, ans, bits);
        return ans;
    }
};