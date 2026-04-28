class Solution {
    typedef long long ll;

    int brute(vector<int>&nums){
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

    int better(vector<int>& nums){
  

        sort(nums.begin(), nums.end());

        //see code with alisha youtube
        //we want to min the moves . so we need to choose middle element
        // 1 3 7 8 11
        //here middle is 7 so we will get moves to make every element as 7. 
        // in left of 7 . we do (nums[left]+x)=7   where x is added to nums[i] to make it 7 so(nums[left]+x)

        //in right of 7 . we do (nums[right]-y)=7   where y is sub to nums[i] to make it 7 so(nums[left]-y)
        
        // and we know both eq wants to become 7 so

        //left = right= 7
        //nums[left]+x = nums[right]-y = 7 
        //which gives ,
        //x+y= nums[right]-nums[left];



        int left=0;
        int right=nums.size()-1;
        ll ans=0;

        while(left<=right){
            
            if((nums[left]>0 && nums[right]>0)  || (nums[left]<0 && nums[right]<0)){
                ans+=abs(abs(nums[right])- abs(nums[left]));
            }
            else{
                ans+=abs(abs(nums[right])+ abs(nums[left]));
            }

            left++;
            right--;
        }


        return ans;
        }
public:
    int minMoves2(vector<int>& nums) {
        //return brute(nums);

        return better(nums);
    }
};