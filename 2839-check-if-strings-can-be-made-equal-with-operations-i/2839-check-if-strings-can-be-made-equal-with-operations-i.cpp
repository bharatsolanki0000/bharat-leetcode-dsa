class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        
        int i=0;
        int j=2;
        int k=0;

        while(j<s1.length()){

            if(s1[i]!=s2[k] && s1[j]!=s2[k]){
                return false;
            }
            else if(s1[j]==s2[k]){
                swap(s1[i], s1[j]);
              
            }
              i++;
              j++;
              k++;
        }

        while(i<s1.length()){
            if(s1[i]!=s2[k]){
                return false;
            }
            i++;
            k++;
        }

        return true;
    }
};