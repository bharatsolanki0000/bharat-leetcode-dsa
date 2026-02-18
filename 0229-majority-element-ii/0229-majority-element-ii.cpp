class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int first=-1;
        int fcount=0;
        int second=-1;
        int scount=0;

        for(int i=0;i<nums.size();i++){
            
            if(first==nums[i]){
                fcount++;
            }
            else if(second==nums[i]){
                scount++;
            }

            else if(scount==0){
                second=nums[i];
                scount++;
            }

            else if(fcount==0){
                fcount++;
                first=nums[i];
            }
            else{
                fcount--;
                scount--;
            }

        }

        // get freq
        fcount=0, scount=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==first){
                fcount++;
            }
            else if(nums[i]==second){
                scount++;
            }
        }


        vector<int> ans;
        int exceed=nums.size()/3;
        if(fcount>exceed){
            ans.push_back(first);
        }
        if(scount>exceed){
            ans.push_back(second);
        }
        
        return ans;
    }
};