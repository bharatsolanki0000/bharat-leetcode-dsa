class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int land=INT_MAX;
        int water=INT_MAX;

        int waterToLand=INT_MAX;
        int landToWater=INT_MAX;

        for(int i=0;i<landStartTime.size();i++){
            land=min(land, landStartTime[i]+landDuration[i]);
        }

        for(int i=0;i<waterStartTime.size();i++){
            water=min(water, waterStartTime[i]+waterDuration[i]);
        }

        //land ->water

        for(int i=0;i<waterStartTime.size();i++){
            int temp=max(land,waterStartTime[i])+waterDuration[i];
            landToWater=min(landToWater, temp);
        }

        //water ->land

         for(int i=0;i<landStartTime.size();i++){
            int temp=max(water,landStartTime[i])+landDuration[i];
            waterToLand=min(waterToLand,temp);
        }

        return min(waterToLand, landToWater);



    }
};