class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxval=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxval=max(maxval,nums[i]);
        }
        int ans=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxval){
                count++;
                ans=max(ans,count);
            }
            else{
                count=0;
            }
        }
        return ans;
    }
};