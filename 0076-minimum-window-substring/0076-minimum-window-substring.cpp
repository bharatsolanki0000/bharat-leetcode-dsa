class Solution {

    bool check(vector<int> &targetFreq, vector<int> &freq, string t){

        for(int i=0;i<t.length();i++){
            int index=t[i]-'a';

            if(freq[index]!=targetFreq[index]){
                return false;
            }
        }

        return true;
        
    }
public:
    string minWindow(string s, string t) {
       

       unordered_map<char,int> freq;

        for(int i=0;i<t.length();i++){
            freq[t[i]]++;
        }
         
        int i=0;
        int j=0;
        int start=-1;
        int count=0;
        int minLen=INT_MAX;

        while(j<s.length()){

            if(freq[s[j]]>0){
                count++;
            }
            freq[s[j]]--;

            while(count==t.length()){

                if(j-i+1 <= minLen){
                    minLen=j-i+1;
                    start=i;
                }

                freq[s[i]]++;
                if(freq[s[i]]>0){
                    count--;
                }
                i++;

            }
            j++;

        }

        return start==-1?"" : s.substr(start, minLen);
    }
};