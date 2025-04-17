class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // start from index 2 ;
        // we are dealing with start=2 , check start-2 & start-1 
        // if equal to nums[index] then do nothing else nums[start]=nums[index];
        if(nums.size()<=2){
            return nums.size();
        }
        int count=2;
        int start=2;
        for(int i=2;i<nums.size();i++){
            if(nums[start-2] != nums[i]){
                nums[start]=nums[i];
                start++;
                count++;
            }
        }
    return count;
    }
};