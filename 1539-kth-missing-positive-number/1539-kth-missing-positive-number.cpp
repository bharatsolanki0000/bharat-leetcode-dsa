class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int i=0;
        while(i<arr.size() && arr[i]<=k){
            k++;
            i++;
        }
        return k;
    }
};