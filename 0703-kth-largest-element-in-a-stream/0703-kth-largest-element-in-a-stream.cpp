class KthLargest {
    priority_queue<int,vector<int> ,greater<int>> minHeap;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K=k;
        
        for(int i=0;i<nums.size();i++){

            if(minHeap.size()==k){
                if(minHeap.top()<nums[i]){
                    minHeap.pop();
                    minHeap.push(nums[i]);
                }
            }
            else{
                minHeap.push(nums[i]);
                K--;
            }
        }
    }
    
    int add(int val) {

        if(K>0){
            minHeap.push(val);
            K--;
        }
        else if(minHeap.top()<val){
            minHeap.pop();
            minHeap.push(val);
        }

        return minHeap.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */