class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int wallet=nums[0];
        int bank=nums[0];      // max Reach, will store index
        int jump=1;
        for(int i=1;i<nums.size();i++){
            wallet--;
            bank--;
            bank=max(bank,nums[i]);
            if(wallet==0 && i!=nums.size()-1){
                jump++;
                wallet=bank;
            }
        }
        return jump;
    }
};