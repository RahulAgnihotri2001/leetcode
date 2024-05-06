class Solution {
public:
    int func(vector<int>&nums,vector<int> &dp,int target){
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(dp[target]!=-1){
            return dp[target];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans+func(nums,dp,target-nums[i]);
        }
        dp[target]=ans;
        return dp[target];
    }


    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return func(nums,dp,target);
    }
};