class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int start=0;
        int answer=0;
        for(int end=0;end<nums.size();end++){
            mp[nums[end]]++;
            if(mp[nums[end]]>k){
                while(mp[nums[end]]>k){
                    mp[nums[start]]--;
                    start++;
                }
            }
            else{
                answer=max(answer,end-start+1);
            }
        }
        return answer;
    }
};