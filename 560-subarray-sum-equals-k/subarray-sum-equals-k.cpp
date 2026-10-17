class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int answer = 0;
        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
            int a =sum;
            for(int j=i;j>=0;j--){
                a=a-nums[j];
                if(sum-a==k){
                    answer++;
                }
            }
        }
        return answer;
    }
};