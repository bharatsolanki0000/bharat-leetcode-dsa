class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left=0;
        int right=0;

        for(int i=0;i<moves.length();i++){
            if(moves[i]=='L'){
                left++;
            }
            else if(moves[i]=='R'){
                right++;
            }
        }


        char dash;
        if(left>right){
            dash='L';
        }
        else{
            dash='R';
        }


        int step=0;
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='L'){
                step--;
            }
            else if(moves[i]=='R'){
                step++;
            }
            else{

                if(dash=='L'){
                    step--;
                }
                else{
                    step++;
                }
            }
        }

        return abs(step);
    }
};