class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Sort as well as save the index
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        sort(nums.begin(),nums.end());
        int start=0;
        int end = nums.size()-1;
        while(start < end){
            if(nums[start]+nums[end]== target){
                vector<int> vec;
                if(nums[start]!= nums[end])
                    vec={mp[nums[start]][0],mp[nums[end]][0]};
                else{
                    vec={mp[nums[start]][0],mp[nums[end]][1]};
                }
                return vec;
            }
            if(nums[start]+nums[end]> target){
                end--;
            }
            else{
                start++;
            }
        }
        vector<int> ans;
        return ans;
    }
};