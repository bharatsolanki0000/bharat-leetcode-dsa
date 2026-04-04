class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(encodedText.length()==0){
            return "";
        }

        int cols=encodedText.length()/rows;

        vector<vector<char>> grid(rows, vector<char> (cols,' '));

        int index=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                grid[i][j]=encodedText[index++];
            }
        }

        
        string ans="";
        

        int i=0;
        int j=0;
        int k=0;
        int flag=false;
        while(k<cols){

            while(i<rows && j<cols){
                ans.push_back(grid[i++][j++]); 
            }

            i=0;
            k++;
            j=k;

        }

        while(ans[ans.length()-1]==' '){
            ans.pop_back();
        }

        return ans;
    }
};