class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        bitset<32> bits(n);
        int lastBit=log2(n);

        for(int i=0;i<=lastBit;i++){
            if(bits[i]==bits[i+1]){
                return false;
            }
        }
        return true;
    }
};