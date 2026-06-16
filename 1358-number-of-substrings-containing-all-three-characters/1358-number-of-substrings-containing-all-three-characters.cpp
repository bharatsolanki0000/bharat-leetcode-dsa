class Solution {
public:
    int numberOfSubstrings(string s) {
        
        vector<int> index={-1,-1,-1};
        //                 a   b  c
        int ans=0;
        int j=0;
        while(j<s.length()){

            if(s[j]=='a'){
                index[0]=j;
            }
            else if(s[j]=='b'){
                index[1]=j;
            }
            else{
                index[2]=j;
            }

            if(index[0]!=-1 && index[1]!=-1 && index[2]!=-1){

                int subStartIndex=min(index[0], min(index[1], index[2]));
                ans+=(1+subStartIndex);
                //   that substring + all prev elements
            }
            j++;
        }
        return ans;
    }
};