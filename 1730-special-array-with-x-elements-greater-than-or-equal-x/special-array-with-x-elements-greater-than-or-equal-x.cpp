class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<=nums[0]){
            return nums.size();
        }
        for(int i=1;i<nums.size();i++){
            if(nums.size()-i<=nums[i] && nums.size()-i>nums[i-1]){
                return nums.size()-i;
            }
        }
        return -1;
    }
};