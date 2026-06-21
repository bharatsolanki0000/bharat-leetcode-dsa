
bool cmp(vector<int> &a, vector<int> &b){
    return a[1]>b[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);

        long long ans=0;
        
        int i=0;
        while(i<boxTypes.size() && truckSize){  
            int box=boxTypes[i][0];
            int profit=boxTypes[i][1];

            if(truckSize-box>=0){
                truckSize-=box;
                ans+=(box*profit);
            }
            else{
                ans+=(truckSize*profit);
                break;
            }
            i++;
        }
        return ans;
    }
};