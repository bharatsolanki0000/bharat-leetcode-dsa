class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        unordered_map<char,int> lower, upper;
        int ans = 0;

        // last occurrence of lowercase
        for(int i = 0; i < word.length(); i++){

            char element = word[i];

            if(element >= 'a' && element <= 'z'){
                lower[element] = i;
            }
        }

        // first occurrence of uppercase
        for(int i = 0; i < word.length(); i++){

            char element = word[i];

            if(element >= 'A' && element <= 'Z' && !upper.count(element)){
                upper[element] = i;
            }
        }

        for(auto &ch : upper){

            char upWord = ch.first;
            int upIndex = ch.second;

            char loWord = upWord - 'A' + 'a';

            if(lower.count(loWord) && lower[loWord] < upIndex){
                ans++;
            }
        }

        return ans;
    }
};