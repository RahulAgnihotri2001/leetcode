class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        if(nums.size()<3){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int x=nums.size()-1;
        int y=nums.size()-2;
        int z=nums.size()-3;
        while(z>=0){
        if(nums[z]+nums[y]>nums[x]){
            return nums[z]+nums[y]+nums[x];
        }
        else{
            z--;
            y--;
            x--;
        }
        }
        return 0;
    }
};