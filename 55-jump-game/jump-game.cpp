class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach=nums[0];
        for(int i=0;i<nums.size();i++){
            reach = max(reach , nums[i]+i);
            if(reach<=i && i!=nums.size()-1){
                return false;
            }
        }
        return true;
    }
};