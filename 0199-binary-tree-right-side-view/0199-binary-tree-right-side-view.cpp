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
    vector<int> rightSideView(TreeNode* root) {

        if(!root){
            return {};
        }
         
         queue<pair<int,TreeNode*>> q;
         //         level  node
         q.push({0,root});

         map<int,int> visited;
         //  level  data

         while(!q.empty()){

            int size=q.size();
            while(size--){

                auto top=q.front();
                q.pop();

                int level=top.first;
                TreeNode* node=top.second;

                if(!visited.count(level)){
                    visited[level]=node->val;
                }

                if(node->right){
                    q.push({level+1,node->right});
                }
                
                if(node->left){
                    q.push({level+1,node->left});
                }
            }

         }
        
        vector<int>ans;

         for(auto mp:visited){
            ans.push_back(mp.second);
         }

         return ans;
        
    }
};