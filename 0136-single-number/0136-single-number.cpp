class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int Xor=0;

        for(int t:nums){
            Xor^=t;
        }
        return Xor;
    }
};