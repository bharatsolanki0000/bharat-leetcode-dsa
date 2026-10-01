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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;

        if(!root){
            return {};
        }

        bool change=true;
        q.push(root);
        vector<vector<int>> ans;

        while(!q.empty()){

            int size=q.size();
            vector<int> temp;

            while(size--){
                TreeNode*frontNode=q.front();
                q.pop();

                temp.push_back(frontNode->val);

                if(frontNode->left){
                    q.push(frontNode->left);
                }

                if(frontNode->right){
                    q.push(frontNode->right);
                }

            }

            if(!change){
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);

            change=!change;
        }

        return ans;
    }
};