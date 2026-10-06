class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if (root == nullptr) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1});

        long long ans = 1;

        while (!q.empty()) {

            int size = q.size();

            long long start = q.front().second;
            long long end = start;

            while (size--) {

                auto top = q.front();
                q.pop();

                TreeNode* node = top.first;
                long long count = top.second;

                long long index=count-start;

                end = count;

                if (node->left) {
                    q.push({node->left, 2 * index});
                }

                if (node->right) {
                    q.push({node->right, 2 * index + 1});
                }
            }

            ans = max(ans, end - start + 1);
        }

        return ans;
    }
};