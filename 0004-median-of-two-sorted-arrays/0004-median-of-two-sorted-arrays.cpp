class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size();
        int n2=nums2.size();

        


        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }

        int start=0;
        int end=n1;
        int size=n1+n2;

        int leftSize=(n1+n2+1)/2;

        while(start<=end){

            int mid1=start+(end-start)/2;
            int mid2=leftSize-mid1;

            int l1=INT_MIN,l2=INT_MIN;
            int r2=INT_MAX, r1=INT_MAX;

            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];

            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];

            if(l1<=r2 && l2<=r1){

                if(size%2!=0){
                    return max(l1,l2);
                }

                return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
            }
            else if(l1>r2){
                end=mid1-1;
            }
            else{
                start=mid1+1;
            }
            

        }
        return 0;

        

        
    }
};