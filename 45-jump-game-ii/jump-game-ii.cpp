class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int wallet=nums[0];
        int account = nums[0];
        int jump=1;
        for(int i=1;i<nums.size();i++){
            if(wallet<i){
                wallet = account;
                jump++;
            }
            account = max(account,i+nums[i]);
        }
        return jump;
    }
};