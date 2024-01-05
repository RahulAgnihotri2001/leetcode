class Solution {
public:

    int fun(int index,int previous,vector<vector<int>> &dp,vector<int>& nums){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index][previous+1]!=-1){
            return dp[index][previous+1];
        }
        int a=0;
        if(previous==-1 || nums[index]>nums[previous]){
            a=1+fun(index+1,index,dp,nums);
        }
        int b=fun(index+1,previous,dp,nums);
        dp[index][previous+1]=max(a,b);
        return dp[index][previous+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int previous=-1;
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        int index=0;
        return fun(index,previous,dp,nums);
    }
};