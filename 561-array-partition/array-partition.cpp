class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int answer=0;
        for(int i=0;i<nums.size();i=i+2){
            answer=answer+nums[i];
        }
        return answer;
    }
};