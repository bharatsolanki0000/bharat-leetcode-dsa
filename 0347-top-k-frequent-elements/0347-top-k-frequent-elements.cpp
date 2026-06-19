class Solution {

    int quickSelect(vector<int>& temp, int start, int end, int k){

        if(start==end){
            return start;
        }

        int pivot=temp[start];
        int i=start+1;
        int j=end;

        while(i<=j){

            while(i<=j && temp[i]<pivot){
                i++;
            }

            while(i<=j && temp[j]>pivot){
                j--;
            }

            if(i<=j){
                swap(temp[i], temp[j]);
                i++;
                j--;
            }
        }

        swap(temp[start], temp[j]);

        if(k<j){
            return quickSelect(temp,start,j-1,k);
        }
        else if(k>j){
            return quickSelect(temp, j+1,end,k);
        }
        else{
            return j;
        }
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> freq;
        for(auto num:nums){
            freq[num]++;
        }

        vector<int>temp;

        for(auto mp:freq){
            temp.push_back(mp.second);
        }


        int pivotFreq=quickSelect(temp, 0, temp.size()-1, temp.size()-k);
        vector<int> ans;

        int pivotElement=temp[pivotFreq];

        for(auto mp:freq){
            if(mp.second>=pivotElement){
                ans.push_back(mp.first);
            }
        }
        
        return ans;
    }
}; 