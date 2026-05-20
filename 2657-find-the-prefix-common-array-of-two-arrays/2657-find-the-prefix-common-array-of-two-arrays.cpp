class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        if(A.size()==1){
            
            if(A[0]==B[0]){
                return {1};
            }
            return {0};
        }
        
        unordered_map<int,int> mp;
        vector<int> ans(A.size(),0);

        for(int i=0;i<A.size();i++){


            if(A[i]==B[i]){
                ans[i]++;
                mp[A[i]]++;
            }
            else{

                if(mp.count(A[i])){
                ans[i]++;
                }
                else{
                    mp[A[i]]++;
                }


                if(mp.count(B[i])){
                    ans[i]++;
                }
                else{
                    mp[B[i]]++;
                }

            }

            if(i>0){
                ans[i]+=ans[i-1];
            }
            
        }

        return ans;
    }
};