class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> answer; // Storing smaller count 
        answer.push_back(0);
        for(int i=1;i<nums.size();i++){
            int temp=0;
            for(int j=answer.size()-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    temp=max(temp,answer[j]+1);
                }
            }
            answer.push_back(temp);
        }
        int ans=0;
        for(int i=0;i<answer.size();i++){
            ans=max(ans,answer[i]);
        }
        return ans+1;
    }
};