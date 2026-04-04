class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(encodedText.length()==0){
            return "";
        }

        int cols=encodedText.length()/rows;

        
        int size=encodedText.length();
        string ans="";

        for(int j=0;j<cols;j++){
            for(int index=j;index<encodedText.length();index=index+cols+1){
                ans.push_back(encodedText[index]);
            }
        }

        while(ans[ans.length()-1]==' '){
            ans.pop_back();
        }
        

        return ans;
    }
};