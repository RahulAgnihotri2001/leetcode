class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0;
        if(nums.size()==1){
            return 0;
        }
        int wallet = nums[0];
        int range = nums[0];
        for(int i=1;i<nums.size();i++){
            range = max(range, nums[i]+i);
            if(wallet == i && i!=nums.size()-1){
                jump++;
                wallet = range;
            }
        }
        return jump+1;
    }
};