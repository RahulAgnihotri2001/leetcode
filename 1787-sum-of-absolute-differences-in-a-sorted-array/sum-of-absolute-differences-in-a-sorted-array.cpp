class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        // maintain right sum
        // maintain left sum
        // value=nums[i]*(count of elements on left)-left sum + right sum -nums[i]*( count of elements on right)
        vector<int> leftsum;
        vector<int> rightsum;
        vector<int> answer;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            leftsum.push_back(sum);
            sum=sum+nums[i];
        }
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            rightsum.push_back(sum);
            sum=sum+nums[i];
        }
        reverse(rightsum.begin(),rightsum.end());
        for(int i=0;i<nums.size();i++){
            int x=nums[i]*(i-0)-leftsum[i]+rightsum[i]-nums[i]*(nums.size()-1-i);
            answer.push_back(x);
        }
        return answer;
    }

};