class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> mp;
        int answer=0;
        for(int i=0;i<nums.size();i++){
            answer=answer+mp[nums[i]];
            mp[nums[i]]++;
        }
        return answer;
    }
};