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
public:
    vector<int> inorderTraversal(TreeNode* root) {

        if(!root){
            return {};
        }

        if(!root->left && !root->right){
            return {root->val};
        }
        
        vector<int>ans;
        
        while(root){

            TreeNode* curr=root->left;

            if(curr){

                TreeNode* pre=curr;
                while(pre->right){
                    pre=pre->right;
                }

                pre->right=root;
            }
            else{
                ans.push_back(root->val);
                root=root->right;
            }
            
            if(curr){
                root->left=nullptr;
                 root=curr;
            }
           
            
        }


        return ans;
    }
};