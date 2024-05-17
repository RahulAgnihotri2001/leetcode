class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int a=INT_MAX;
        int b=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==a){
                b++;
            }
            else{
                if(b==0){
                    a=nums[i];
                    b=1;
                }
                else{
                    b--;
                }
            }
        }
        return a;
    }
};