/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string ans="";

        if(!root){
            return "";
        }

        queue<TreeNode*> q;
        q.push({root});
        ans=to_string(root->val);
       

        while(!q.empty()){

          
            int size=q.size();
            while(size--){

                auto frontNode=q.front();
                q.pop();


                ans+=',';
                if(frontNode->left){
                    ans=ans+to_string(frontNode->left->val);
                    q.push({frontNode->left});
                }
                else{
                    ans.push_back('n');
                }

                ans+=',';

                
                if(frontNode->right){
                    q.push({frontNode->right});
                    ans=ans+to_string(frontNode->right->val);
                }
                else{
                    ans.push_back('n');
                }

                
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if(data.empty()) return nullptr;
      
        stringstream ss(data);
        string val;

        getline(ss,val,',');

        TreeNode* root=new TreeNode(stoi(val));

        queue<TreeNode*> q;

        q.push({root});

        while(!q.empty()){

            TreeNode* node=q.front();
            q.pop();

            

            if(getline(ss,val,',') && val!="n"){
                node->left=new TreeNode(stoi(val));
                q.push(node->left);
            }

           

            if(getline(ss,val,',') && val!="n"){
                node->right=new TreeNode(stoi(val));
                q.push(node->right);
            }


        }

        return root;


    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));