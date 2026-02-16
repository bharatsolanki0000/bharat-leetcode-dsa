class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size()==1){
            return 0;
        }

        int profit=0;
        int buy=prices[0];
        for(int i=0;i<prices.size();i++){
            
            buy=min(prices[i], buy);
            profit=max(profit, prices[i]-buy);
        }
        return profit;
    }
};