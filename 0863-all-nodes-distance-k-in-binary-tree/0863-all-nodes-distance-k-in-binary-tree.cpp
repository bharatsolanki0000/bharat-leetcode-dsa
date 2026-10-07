class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<int, vector<int>> adj;

        // Build undirected graph
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                q.push(node->left);

                adj[node->val].push_back(node->left->val);
                adj[node->left->val].push_back(node->val);
            }

            if(node->right) {
                q.push(node->right);

                adj[node->val].push_back(node->right->val);
                adj[node->right->val].push_back(node->val);
            }
        }

        // BFS from target
        queue<int> qw;
        qw.push(target->val);

        unordered_map<int, int> visited;
        visited[target->val] = 1;

        while(!qw.empty()) {

            int size = qw.size();

            // All nodes currently in queue are at distance k
            if(k == 0) {
                vector<int> ans;

                while(!qw.empty()) {
                    ans.push_back(qw.front());
                    qw.pop();
                }

                return ans;
            }

            while(size--) {

                int node = qw.front();
                qw.pop();

                for(auto neigh : adj[node]) {

                    if(!visited[neigh]) {
                        visited[neigh] = 1;
                        qw.push(neigh);
                    }
                }
            }

            k--;
        }

        return {};
    }
};