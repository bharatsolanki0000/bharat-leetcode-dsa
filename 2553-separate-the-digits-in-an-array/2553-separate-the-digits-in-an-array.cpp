class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> ans;
        for(int i=0;i<nums.size();i++){

            string element=to_string(nums[i]);

            int j=0;
            while(j<element.length()){
                ans.push_back((int)element[j]-'0');
                j++;
            }
        }
        return ans;


    }
};