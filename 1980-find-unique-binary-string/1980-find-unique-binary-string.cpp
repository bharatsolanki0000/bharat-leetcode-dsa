class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans(nums.size(), '0');

        int j=0;
        for(int i=0;i<nums.size();i++){

            if(nums[i][j]=='1'){
                ans[i]='0';
            }
            else{
                ans[i]='1';
            }
            j++;
        }
        return ans;
    }
};