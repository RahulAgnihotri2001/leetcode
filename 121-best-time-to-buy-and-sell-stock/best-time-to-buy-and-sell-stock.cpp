class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer=0;
        int minimum = prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>minimum){
                answer=max(answer,(prices[i]-minimum));
            }
            minimum = min(minimum,prices[i]);
        }
        return answer;
    }
};