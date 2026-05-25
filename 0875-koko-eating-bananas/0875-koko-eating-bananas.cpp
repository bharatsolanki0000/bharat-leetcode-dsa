class Solution {

    bool check(vector<int>& piles, int h, int k){

        long long time=0;
        int i=0;

        while(i<piles.size() && time<h){
            time+=ceil((double)piles[i]/k);
            i++;
        }

        if(i==piles.size() && time<=h){
            return true;
        }

        return false;
        

        
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int start=1;
        int end=*max_element(piles.begin(), piles.end());
        int ans=0;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(check(piles, h , mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }

        return ans;
    }
};