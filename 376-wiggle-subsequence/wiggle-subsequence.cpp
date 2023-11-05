class Solution {
public:
    int wiggleMaxLength(vector<int>& num) {
        if(num.size()==1){
            return num.size();
        }
        int answer=0;
        vector<int> nums;
        nums.push_back(num[0]);
        for(int i=1;i<num.size();i++){
            if(num[i]!=num[i-1]){
                nums.push_back(num[i]);
            }
        }
        if(nums.size()==1){
            return nums.size();
        }
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                answer++;
            }
        }
        int b=0;
        if(nums[0]>nums[1]){
            b++;
        }
        if(nums[nums.size()-1]>nums[nums.size()-2]){
            b++;
        }
        answer=answer+b;
        int c=answer-1;
        if(nums[0]<nums[1]){
            c++;
        }
        if(nums[nums.size()-1]<nums[nums.size()-2]){
            c++;
        }
        return answer+c;
    }
};