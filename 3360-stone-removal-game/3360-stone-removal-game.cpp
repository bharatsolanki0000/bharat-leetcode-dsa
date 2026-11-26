class Solution {

    bool solve(int n, int stones){

        if(n<stones){

            if(stones%2!=0){
                return true;
            }

            return false;

        }

        return solve(n-stones,stones-1);
    }
public:
    bool canAliceWin(int n) {
        

        return solve(n,10);
    }
};