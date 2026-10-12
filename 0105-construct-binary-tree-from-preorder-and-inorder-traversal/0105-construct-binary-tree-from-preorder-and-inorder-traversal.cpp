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

    TreeNode* solve(vector<int>&preorder, vector<int>&inorder, int start, int end, int &preIndex){

       
        if(preIndex>=preorder.size()){
            return nullptr;
        }

        if(start>end){
            return nullptr;
        }


        int rootValue=preorder[preIndex++];
        TreeNode* root=new TreeNode(rootValue);

        int minIndex;
        for(int i=start;i<=end;i++){
            if(rootValue==inorder[i]){
                minIndex=i;
                break;
            }
        }

        

        root->left=solve(preorder, inorder,start,minIndex-1,preIndex);
        root->right=solve(preorder, inorder,minIndex+1,end,preIndex);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex=0;
        return solve(preorder,inorder,0,inorder.size()-1,preIndex);
    }
};