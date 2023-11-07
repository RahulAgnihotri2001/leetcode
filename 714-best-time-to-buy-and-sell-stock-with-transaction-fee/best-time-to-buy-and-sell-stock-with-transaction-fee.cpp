class Solution {
public:
     // Dp solution

    int fun(int index,int state,vector<int>& prices, int fee,vector<vector<int>> &dp){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[state][index]!=-1){
            return dp[state][index];
        }
        int x=INT_MIN;
        if(state==0){
            // lelo
            x=fun(index+1,1,prices,fee,dp)-fee-prices[index];
        }
        if(state==1){
            x=fun(index+1,0,prices,fee,dp)+prices[index];
        }
           int y=fun(index+1,state,prices,fee,dp);
           dp[state][index]= max(x,y);
           return dp[state][index];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int index=0;
        int state=0;   // 0 can buy   1 only sell
        vector<vector<int>> dp(2,vector<int>(prices.size(),-1));
        int answer=fun(index,state,prices,fee,dp);
        return answer;   
    }
};