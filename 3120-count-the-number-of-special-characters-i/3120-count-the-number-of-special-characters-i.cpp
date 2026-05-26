class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        unordered_map<char,int> mp;
        int ans=0;

        for(int i=0;i<word.length();i++){

            if(word[i]>='a' && word[i]<='z' && !mp.count(word[i])){
                
                char newWord=word[i]-'a'+'A';

                if(mp.count(newWord)){
                    ans++;
                }
            }
            else if(word[i]>='A' && word[i]<='Z' && !mp.count(word[i])){

                char newWord=word[i]-'A'+'a';

                if(mp.count(newWord)){
                    ans++;
                }

            }
            mp[word[i]]++;
        }


        return ans;
    }
};