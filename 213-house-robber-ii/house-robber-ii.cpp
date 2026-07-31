class Solution {
public:
    int rob(vector<int>& nums) {
        // store one more state if starting taken or not
        if(nums.size()==1){
            return nums[0];
        }
        vector<vector<int>> dp(2,vector<int>(nums.size(),-1));
        int a = fun(0,1,nums,dp);    // state (0 means first element  not taken) , index 
        int b = nums[0] + fun(1,2,nums,dp);
        return max(a,b);
    }

    int fun(int flag, int index, vector<int> &nums, vector<vector<int>> &dp){
        if(index>=nums.size()){
            return 0;
        }
        if(index == nums.size()-1){
            if(flag == 0){
                return nums[index];
            }
            else 
                return 0;
        }
        if(dp[flag][index]!=-1){
            return dp[flag][index];
        }
        dp[flag][index]= max(nums[index]+fun(flag,index+2,nums,dp ), fun(flag,index+1,nums,dp));
        return dp[flag][index];
    }


};