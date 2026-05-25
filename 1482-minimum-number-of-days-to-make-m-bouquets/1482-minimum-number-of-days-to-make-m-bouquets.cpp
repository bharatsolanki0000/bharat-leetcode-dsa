class Solution {

    bool check(vector<int>& bloomDay, int m, int k, int day){

      
        int flower=0;
        int bunch=0;
        
        for(int i=0;i<bloomDay.size();i++){

            if(bloomDay[i]<=day){
                flower++;

                if(flower==k){
                    bunch++;
                    flower=0;
                }
            }
            else{
                flower=0;
            }

        }

        return bunch>=m;
       
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        if((long)m*k>bloomDay.size()){
            return -1;
        }

        int start=*min_element(bloomDay.begin(), bloomDay.end());;
        int end=*max_element(bloomDay.begin(), bloomDay.end());
        int ans=-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(check(bloomDay, m,k, mid)){
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