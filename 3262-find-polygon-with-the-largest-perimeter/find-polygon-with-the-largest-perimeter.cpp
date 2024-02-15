class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        long long sum=0;
        vector<long long> vec(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            vec[i]=sum;
            sum=sum+nums[i];
        }
        int index=0;
        while(index<nums.size() && nums[index]>=vec[index]){
            index++;
        }
        if(index<=nums.size()-3)
            return vec[index]+nums[index];
        return -1;
    }
};