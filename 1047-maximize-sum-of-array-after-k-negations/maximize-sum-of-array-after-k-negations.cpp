class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int index=0;
        while(index<nums.size() && nums[index]<0){
            if(k==0){
                break;
            }
            nums[index]=-1*nums[index];
            k--;
            index++;
        }
        if(index==nums.size() || k!=0){
            sort(nums.begin(),nums.end());
            if(k%2==1){
                nums[0]=-1*nums[0];
            }
        }
        /*
        else if(k!=0){
            if(k%2==1){
                nums[index]=-1*nums[index];
            }
        }
        */
        int answer=0;
            for(int i=0;i<nums.size();i++){
                answer=answer+nums[i];
            }
         return answer;
    }
};