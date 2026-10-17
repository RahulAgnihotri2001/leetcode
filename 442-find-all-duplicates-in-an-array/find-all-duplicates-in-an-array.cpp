class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer;
        int n = nums.size()+1;
        for(int i=0;i<nums.size();i++){
            nums[(nums[i]-1)%n] =  nums[(nums[i]-1)%n]+ n;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]/n>1){
                answer.push_back(i+1);
            }
        }
        return answer;
    }
};