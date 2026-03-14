class Solution {

    void solve(int n,int k,string temp, string &ans,  int &count){
        
        
        
        if(temp.size()==n){
            count++;
            
            if(count==k){
                ans=temp;
              
            }
              return ;
        }


        for(int i=0;i<3;i++){
            char ch=i+'a';
             if( temp.empty() || temp.back()!=ch){
                solve(n,k,temp+ch, ans, count);
            }

            if(!ans.empty()){
                return ;
            }
        }
        
        
    }
public:
    string getHappyString(int n, int k) {
        
        int count=0;
        string ans="";
        solve(n,k,"", ans,count );

        return ans.empty()?"":ans;
        
   }
};