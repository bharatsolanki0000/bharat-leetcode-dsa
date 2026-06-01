class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        sort(cost.begin(), cost.end());
        int total=0;
        int i=cost.size()-1; 

        while(i>0){

            int first=cost[i];
            int second=cost[i-1];

            total+=first+second;

            
            if(i-2>=0 && cost[i-2]<=second){
                i--;
            }

            i-=2;
        }

        if(i==0){
            total+=cost[0];
        }
        return total;
    }
};