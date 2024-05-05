class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        int i=0,j=nums.size()-1;
        int x= solve(i,j,nums,dp);
        if(x>=(sum-x)){
            return true;
        }
        else{
            return false;
        }
    }
    int solve(int i,int j,vector<int> &nums,vector<vector<int>> &dp){
        if(i==j){
            return nums[i];
        }
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int answeri = nums[i]+min(solve(i+2,j,nums,dp),solve(i+1,j-1,nums,dp));
        int answerj=nums[j]+min(solve(i+1,j-1,nums,dp),solve(i,j-2,nums,dp));
        dp[i][j]= max(answeri,answerj);
        return dp[i][j];
    }
};