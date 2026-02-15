class Solution {

    int solve(vector<vector<int>> &cuboids, int index, int preWeight,int preLength, int preHeight){

        if(index==cuboids.size()){
            return 0;
        }

        //take
        int take=0;
        if((preWeight==-1) || 
        (cuboids[index][0]>=preWeight &&
        cuboids[index][1]>=preLength && 
         cuboids[index][2]>=preHeight)){
            take=cuboids[index][2]+solve(cuboids, index+1, cuboids[index][0], cuboids[index][1], cuboids[index][2] );
        }
        
        int notTake=solve(cuboids, index+1, preWeight, preLength, preHeight);

        return max(take, notTake);
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        
        //sort for height
        for(int i=0;i<cuboids.size();i++){
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        //{ , , h(max)}  max element will be our height 

        //for stacking our w, l should be sorted 
        sort(cuboids.begin(), cuboids.end());

        // now we will do longest incerasing subsequence thing on w and l to get max height 
        return solve(cuboids, 0, -1,-1,-1);

    }
};