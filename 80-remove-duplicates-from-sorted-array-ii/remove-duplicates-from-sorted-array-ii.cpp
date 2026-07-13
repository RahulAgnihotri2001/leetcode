class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int h = nums.size();
        if(h==0 || h==1 || h==2){
            return h;
        }
        int start=2;
        for(int i=2;i<nums.size();i++){
            if(nums[i]!= nums[start-1] || (nums[i]== nums[start-1] && nums[i]!= nums[start-2])){
                nums[start]=nums[i];
                start++;
            }
        }
        return start;
    }
};