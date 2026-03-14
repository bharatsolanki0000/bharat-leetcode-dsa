class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int index=nums1.size()-1;

        while(i>=0 || j>=0) {
            int first=INT_MIN;

            if(i>=0){
                first=nums1[i];
            }

            int second=INT_MIN;
            if(j>=0){
                second=nums2[j];
            }

            if(first>second){
                nums1[index]=first;
                i--;
            }
            else if(first<=second){
                nums1[index]=second;
                j--;
            }
            index--;


        }
    }
};