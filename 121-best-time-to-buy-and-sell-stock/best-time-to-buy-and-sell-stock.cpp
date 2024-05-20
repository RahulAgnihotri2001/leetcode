class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int pur=prices[0];
        for(int i=1;i<prices.size();i++){
            if(pur>prices[i]){
                pur=prices[i];
            }
            else{
                profit=max(profit,prices[i]-pur);
            }
        }
        return profit;
    }
};