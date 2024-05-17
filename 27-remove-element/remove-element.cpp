class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=-1;
        int k=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=val){
                i++;
                k++;
                swap(nums[i],nums[j]);
            }
        }
        return k;
    }
};