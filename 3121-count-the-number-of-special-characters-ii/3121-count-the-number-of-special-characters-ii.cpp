class Solution {

    int hashMap(string word){
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

    int freqVector(string word){

        vector<int> lower(26,INT_MIN);
        vector<int> upper(26,INT_MAX);

        int ans=0;

       
        for(int i=0;i<word.length();i++){

            char element=word[i];


            //lower char last occurance
            if(element>='a' && element<='z'){
                lower[element-'a']=i;
            }
            else{
                //first occurance of upper letter

                if(upper[element-'A']==INT_MAX){
                    upper[element-'A']=i;
                }
            }

        }

        for(int i=0;i<26;i++){

            if(lower[i]!=INT_MIN && upper[i]!=INT_MAX){

                if(lower[i]<upper[i]){
                    ans++;
                }
            }
        }

        return ans;


    }
public:
    int numberOfSpecialChars(string word) {
        //return hashMap(word);

        return freqVector(word);
        
    }
};