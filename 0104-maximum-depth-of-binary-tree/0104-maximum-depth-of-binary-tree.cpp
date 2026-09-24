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

    int solve(TreeNode* root){
        if(root==nullptr){
            return 0;
        }

        int leftSide=solve(root->left);
        int rightSide=solve(root->right);

        return 1+max(leftSide,rightSide);
    }

    int bfsSolve(TreeNode*root){
        
        if(root==nullptr){
            return 0;
        }

        if(!root->left && !root->right){
            return 1;
        }

        queue<TreeNode*> q;
        q.push(root);
        int ans=0;

        while(!q.empty()){
            ans++;
            int size=q.size();
            while(size--){

                 TreeNode* frontNode=q.front();
                 q.pop();


                if(frontNode->left){
                    q.push(frontNode->left);
                }

                if(frontNode->right){
                    q.push(frontNode->right);
                }

            }

        }

        return ans;
    }


public:
    int maxDepth(TreeNode* root) {
        //return solve(root);

        return bfsSolve(root);
    }
};