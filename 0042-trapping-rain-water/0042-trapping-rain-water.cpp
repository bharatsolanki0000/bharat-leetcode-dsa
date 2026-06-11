class Solution {

    int twoVectors(vector<int>& nums){

        vector<int> prevGreater(nums.size());
        vector<int> nextGreater(nums.size());


        //calculate prev gretaer
        

        prevGreater[0]=nums[0];
       int prevMax= prevGreater[0];
        for(int i=1;i<nums.size();i++){
            
            prevMax=max(prevMax, nums[i]);
            prevGreater[i]=prevMax;
        }

        //calucate next gretaer
       
        nextGreater[nums.size()-1]=nums[nums.size()-1];
        int nextMax=nextGreater[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){

           
            nextMax=max(nextMax, nums[i]);
            nextGreater[i]=nextMax;
        }


        //water stored= min(prev, next)-height
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=min(prevGreater[i], nextGreater[i])-nums[i];
            
        }
        return ans;


    }

    int twoPointers(vector<int>&nums){

        int leftMax=0;
        int rightMax=0;


        int left=0;
        int right=nums.size()-1;
        int ans=0;

        while(left< right){
            leftMax=max(leftMax, nums[left]);
            rightMax=max(rightMax, nums[right]);

            if(leftMax< rightMax){
                ans+=(leftMax)-nums[left];
                left++;
            }
            else{
                ans+=(rightMax)-nums[right];
                right--;
            }
        }

        return ans;
    }
public:
    int trap(vector<int>& height) {
        //return twoVectors(height);

        return twoPointers(height);
    }
};