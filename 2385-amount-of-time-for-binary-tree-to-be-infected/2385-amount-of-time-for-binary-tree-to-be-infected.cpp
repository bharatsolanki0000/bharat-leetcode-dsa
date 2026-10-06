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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> mp;
       // mp[root->val].push_back(-1);

        queue<TreeNode*> q;
        q.push({root});
        
        while(!q.empty()){
            int size=q.size();

            while(size--){
                TreeNode* node=q.front();
                q.pop();

                //left 
                if(node->left){

                    mp[node->val].push_back(node->left->val);
                    mp[node->left->val].push_back(node->val);
                    q.push({node->left});
                }

                //right
                if(node->right){

                    mp[node->right->val].push_back(node->val);
                    mp[node->val].push_back(node->right->val);
                    q.push(node->right);
                }


            }
        }

      
        unordered_map<int,int> visited;

        int time=-1;
        queue<int>p;
        p.push(start);

        visited[start]=1;

        while(!p.empty()){

            time++;
            int size=p.size();
            while(size--){
                int node=p.front();
                p.pop();

                vector<int> childs=mp[node];

                for(int element:childs){
                    if(visited[element]==0){
                        visited[element]=1;
                        p.push(element);
                    }
                }

            }
           
        }

        return time;
    }
};