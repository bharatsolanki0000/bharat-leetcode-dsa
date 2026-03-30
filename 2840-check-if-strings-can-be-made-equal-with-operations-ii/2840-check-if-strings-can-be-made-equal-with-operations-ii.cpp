class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int size=s1.length();

        vector<int> even(26,0);
        vector<int> odd(26,0);

        for(int i=0;i<size;i++){

            if(i%2==0){
                //even
                even[s1[i]-'a']++;
                even[s2[i]-'a']--;
            }
            else{
                odd[s1[i]-'a']++;
                odd[s2[i]-'a']--;
            }
        }

        for(int i=0;i<26;i++){
            if(even[i] || odd[i]){
                return false;
            }
        }
        return true;
    }
};