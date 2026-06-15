class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int totalSum=0;
            for(auto t: cardPoints){
                totalSum+=t;
            }


        // find smallest sum substring of len-k size
        k=cardPoints.size()-k;
        int ans=-1;


        if(k==0){
            return totalSum;
        }

        int prefixSum=0;
        int count=0;
        int i=0,j=0;
        while(j<cardPoints.size()){
            prefixSum+=cardPoints[j];
            count++;

            while(count==k){
                ans=max(ans, totalSum-prefixSum);
                prefixSum-=cardPoints[i];
                count--;
                i++;

            }
            j++;
        }
        return ans;


    }
};