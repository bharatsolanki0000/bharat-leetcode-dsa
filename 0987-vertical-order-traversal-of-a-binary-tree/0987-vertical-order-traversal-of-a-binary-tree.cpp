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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       map<int,map<int,vector<int>>> mp;
        // col     level      num

        queue<pair<TreeNode*,pair<int,int>>> q;
        //          node           col   level


        q.push({root, {0,0}});

        while(!q.empty()){
            int size=q.size();

            while(size--){
                auto top=q.front();
                q.pop();

                TreeNode* node=top.first;
                int col=top.second.first;
                int level=top.second.second;

                mp[col][level].push_back(node->val);

                if(node->left){
                    q.push({node->left,{col-1,level+1}});
                }

                if(node->right){
                    q.push({node->right,{col+1,level+1}});
                }

            }
        }

        vector<vector<int>>ans;

       for (auto &col : mp) {

            vector<int> temp;

            for (auto &level : col.second) {

               
                sort(level.second.begin(), level.second.end());

                
                for (int val : level.second) {
                    temp.push_back(val);
                }
            }

            ans.push_back(temp);
        }

        return ans;

    }
};