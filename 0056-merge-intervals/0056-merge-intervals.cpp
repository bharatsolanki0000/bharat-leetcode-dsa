class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> last;
        int first=intervals[0][0];
        int second=intervals[0][1];

        last.push_back({first,second});


        for(int i=1;i<intervals.size();i++){
            int lastStart=last.back()[0];
            int lastEnd=last.back()[1];

            int currStart=intervals[i][0];
            int currEnd=intervals[i][1];

            if(currStart<=lastEnd){
                lastStart=min(lastStart, currStart);
                lastEnd=max(lastEnd, currEnd);
                last.back()={lastStart, lastEnd};
            }
            else{
                last.push_back(intervals[i]);
            }
        }
        return last;
    }
};