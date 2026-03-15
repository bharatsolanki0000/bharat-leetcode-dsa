class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minIndex=0;
        for(int i=0;i<prices.size();i++){

            if(prices[i]< prices[minIndex]){
                minIndex=i;
            }

            profit=max(profit,prices[i]- prices[minIndex]);
        }

        return profit;
    }
};