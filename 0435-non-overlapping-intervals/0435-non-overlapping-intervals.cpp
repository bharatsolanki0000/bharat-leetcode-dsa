bool cmp(vector<int> &a, vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(),cmp);
        int ans=0;

        int lastEnd=INT_MIN;
        for(int i=0;i<intervals.size();i++){

            int start=intervals[i][0];
            int end=intervals[i][1];

            if(lastEnd!=INT_MIN && lastEnd>start){
                ans++;
            }
            else{
                lastEnd=end;
            }
        }
        return ans;
    }
};