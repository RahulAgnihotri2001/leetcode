class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums.size()-1;
        while(start<end && nums[start]<0 && nums[end]>0){
            if(abs(nums[start])<nums[end]){
                end--;
            }
            else if(abs(nums[start])>nums[end]){
                start++;
            }
            else{
                return nums[end];
            }
        }
        return -1;
    }
};