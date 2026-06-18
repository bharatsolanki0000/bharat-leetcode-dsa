class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>,greater<int>> minHeap;

        for(int i=0;i<k;i++){
            minHeap.push(nums[i]);
        }

        int i=k;
        while(i<nums.size()){

            if(minHeap.top()<nums[i]){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
            i++;
        }

        return minHeap.top();
    }
};