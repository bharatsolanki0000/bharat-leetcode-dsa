class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int totalDecimals=pow(2,k);

        int totalLength=s.length();
        if(totalLength< totalDecimals){
            return false;
        }
        
        set<string>decimalCounts;

        for(int i=0;i<s.length()-k+1;i++){

            string decimal=s.substr(i,k);

            if(!decimalCounts.count(decimal)){
                decimalCounts.insert(decimal);
            }

            if(decimalCounts.size()==totalDecimals){
                return true;
            }
            
        }

        return false;


    }
};