class Solution {
    typedef long long ll;
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        ll ans=LLONG_MAX;

        for(int i=0;i<nums.size();i++){
            ll moves=0;
            for(int j=0;j<nums.size();j++){
                
                if(nums[i]<0 && nums[j]>0){
                    moves+=abs(nums[i])+nums[j];
                }
                else if(nums[i]>0 && nums[j]<0){
                    moves+=abs(nums[j])+nums[i];
                }
                else{

                    moves+=abs(abs(nums[i])-abs(nums[j]));
                }

                if(moves>ans){
                    break;
                }
            }
            ans=min(ans,moves);
        }

        return ans;
    }
};