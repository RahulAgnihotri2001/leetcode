class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(1);
        int p=1;
        for(int i=1;i<nums.size();i++){
            p=p*nums[i-1];
            ans.push_back(p);
        }
        p=1;
        for(int i=nums.size()-2;i>=0;i--){
            p=p*nums[i+1];
            ans[i]=ans[i]*p;   
        }
        return ans;
    }
};