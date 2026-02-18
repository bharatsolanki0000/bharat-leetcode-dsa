class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        //right shift
        long long newBits=n>>1;

        long long xored=n^newBits;

        return (xored & xored+1)==0;
        
    }
};