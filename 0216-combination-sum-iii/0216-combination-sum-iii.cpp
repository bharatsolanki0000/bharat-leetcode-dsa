class Solution {

    void solve(int &k, int n,vector<vector<int>> &ans,vector<int>&temp,int numValue){

        if(temp.size()==k){

            if(n==0){
                ans.push_back(temp);
            }
            return ;
        }

        if(numValue>9){
            return; 
        }

        for(int num=numValue;num<=9;num++){

            if(num<=n){
                temp.push_back(num);
                solve(k,n-num, ans,temp,num+1);
                temp.pop_back();
            }
            else{
                return ;
            }
        }
        
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>temp;
        solve(k,n,ans,temp,1);
        return ans;
    }
};