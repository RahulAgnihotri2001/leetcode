class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int evenpoint=0;
        int oddpoint=1;
        vector<int> vec(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                vec[evenpoint]=nums[i];
                evenpoint=evenpoint+2;
            }
            else{
                vec[oddpoint]=nums[i];
                oddpoint+=2;
            }
        }
        return vec;
    }
};