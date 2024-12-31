class Solution {
public:

    int func(int index, int range,vector<int>& days, vector<int>& cost,vector<vector<int>> &dp){
        if(index>days.size()-1){
            return 0;
        }
        if(dp[index][range]!=-1){
            return dp[index][range];
        }
        if(range<days[index]){
            int temp=INT_MAX;
            temp = min(temp,cost[0]+func(index+1,days[index],days,cost,dp));
            temp = min(temp,cost[1]+func(index+1,days[index]+6,days,cost,dp));
            temp = min(temp,cost[2]+func(index+1,days[index]+29,days,cost,dp));
            dp[index][range]= temp;
        }
        else{
            dp[index][range] = func(index+1,range,days,cost,dp);
        }
        return dp[index][range];
    }

    int mincostTickets(vector<int>& days, vector<int>& cost) {
        sort(days.begin(),days.end());
        int index=0;
        int range=0;
        int maxday=days[days.size()-1];
        vector<vector<int>> dp;
        for(int i=0;i<days.size();i++){
            vector<int> temp;
            for(int j=0;j<maxday+31;j++){
                temp.push_back(-1);
            }
            dp.push_back(temp);
        }
        int ans = func(index,range,days,cost,dp);
        return ans;
    }
};