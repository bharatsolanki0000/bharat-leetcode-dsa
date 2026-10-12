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

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start , int end, int &index){

        if(index<0 || start> end){
            return nullptr;
        }

        int rootValue=postorder[index--];
        TreeNode* root=new TreeNode(rootValue);

        int mid=0;

        for(int i=start;i<=end;i++){
            if(rootValue==inorder[i]){
                mid=i;
                break;
            }
        }
         root->right=solve(inorder,postorder, mid+1,end, index);

        root->left=solve(inorder,postorder, start,mid-1, index);
       

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int index=postorder.size()-1;
        return solve(inorder, postorder, 0, inorder.size()-1,index);
    }
};