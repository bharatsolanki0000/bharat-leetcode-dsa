class Solution {

    int brute(string s, int k){
         int ans=0;
        
        for(int i=0;i<s.length();i++){
           unordered_map<char,int> freq;
           int maxFreq=-1;

           for(int j=i;j<s.length();j++){

                freq[s[j]]++;

                maxFreq=max(maxFreq, freq[s[j]]); 
                int totalElement=j-i+1;

                int convertibleElements=totalElement-maxFreq;
                if(convertibleElements<=k){
                    ans=max(ans, totalElement);
                }
           }
            
        }
        return ans;
    }

    int slidingWindow(string s, int k){
        int i=0;
        int j=0;
        vector<int> freq(128);

        int ans=-1;
        int maxFreq=-1;
        while(j<s.length()){
            freq[s[j]]++;
            maxFreq=max(maxFreq, freq[s[j]]);

            
            //while((j-i+1)-maxFreq>k){             second optimal
            if((j-i+1-maxFreq>k)){
                freq[s[i]]--;
               // maxFreq=-1;
                // for(int k=0;k<128;k++){                 first optimal
                //     maxFreq=max(maxFreq, freq[k]);
                // }
                i++;
                
            }
            if(j-i+1-maxFreq<=k){
                ans=max(ans, j-i+1);
            }
            j++;



        }
        return ans;
    }

    
public:
    int characterReplacement(string s, int k) {
        //return brute(s,k);

        return slidingWindow(s,k);
       
    }
};