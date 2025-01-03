class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int answer=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+long(nums[i]);
        }
        long long temp=0;
        for(int i=0;i<nums.size()-1;i++){
            temp=temp+long(nums[i]);
            if(temp>=(sum-temp)){
                answer++;
            }
        }
        return answer;
    }
};