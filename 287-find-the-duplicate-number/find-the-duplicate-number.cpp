class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // get the maximum number  = nums.size()
        int aj=nums.size()+1;
        for(int i=0;i<nums.size();i++){
            nums[nums[i]%aj-1]=nums[nums[i]%aj-1]+aj;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]/aj>1){
                return i+1;
            }
        }
        return -1;
    }
};