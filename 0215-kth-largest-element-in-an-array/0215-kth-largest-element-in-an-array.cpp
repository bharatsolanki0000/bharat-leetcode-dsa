class Solution {

    int heap(vector<int>& nums, int k) {
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

    int optimalCountingSort(vector<int>& nums, int k){

        int maxi=INT_MIN;
        int mini=INT_MAX;

        for(auto num: nums){
            maxi=max(maxi, num);
            mini=min(mini, num);
        }

        vector<int> countArray(maxi-mini+1);

        for(int i=0;i<nums.size();i++){

            //to handle negative numbers
            int index=nums[i]-mini;
            countArray[index]++;
        }

        int remain=k;

        for(int num=countArray.size()-1; num>=0; num--){
            remain-=countArray[ num];

            if(remain<=0){
                return  num+mini;
            }
        }
        return -1;

    }



int quickSelect(vector<int>& nums, int start, int end, int k) {
    if (start == end) {
        return nums[start];
    }

    int pivot = nums[start];
    int i = start + 1;
    int j = end;

    while (i <= j) {

        while (i <= j && nums[i] < pivot) {
            i++;
        }

        while (i <= j && nums[j] > pivot) {
            j--;
        }

        if (i <= j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }

    swap(nums[start], nums[j]);

    if (k < j) {
        return quickSelect(nums, start, j - 1, k);
    }
    else if (k > j) {
        return quickSelect(nums, j + 1, end, k);
    }
    else {
        return nums[j];
    }
}

public:
    int findKthLargest(vector<int>& nums, int k) {
       // return heap(nums,k);


        //optimal using counting sort
       //return optimalCountingSort(nums,k);
        k=nums.size()-k;
       return quickSelect(nums,0,nums.size()-1,k);
    }
};