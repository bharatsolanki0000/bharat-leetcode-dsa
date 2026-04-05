class Solution {
public:
    bool judgeCircle(string moves) {
        
        int row=0;
        int col=0;
        for(int i=0;i<moves.length();i++){

            if(moves[i]=='R'){
                col++;
            }
            else if(moves[i]=='L'){
                col--;
            }
            else if(moves[i]=='U'){
                row--;
            }
            else{
                row++;
            }
        }

        return row==0 && col==0;
    }
};