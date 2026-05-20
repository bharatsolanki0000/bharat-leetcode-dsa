class Solution {

    vector<int> solve1(vector<int>& A, vector<int>& B){
        
        vector<int> mp(51);
        vector<int> ans(A.size(),0);

        for(int i=0;i<A.size();i++){


            if(A[i]==B[i]){
                ans[i]++;
                mp[A[i]]++;
            }
            else{

                if(mp[A[i]]!=0){
                ans[i]++;
                }
                else{
                    mp[A[i]]++;
                }


                if(mp[B[i]]!=0){
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

    
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

          if(A.size()==1){
            
            if(A[0]==B[0]){
                return {1};
            }
            return {0};
        }
        
          return solve1(A,B);
       
    }
};