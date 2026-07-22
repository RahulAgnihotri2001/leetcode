class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prod1;
        vector<int> prod2;
        int pr=1;
        for(int i=0;i<nums.size();i++){
            prod1.push_back(pr);
            pr=pr*nums[i];
        }
        pr=1;
        for(int i=nums.size()-1;i>=0;i--){
            prod2.push_back(pr);
            pr=pr*nums[i];
        }
        reverse(prod2.begin(),prod2.end());
        for(int i=0;i<nums.size();i++){
            prod1[i]= prod1[i] * prod2[i];
        }
        return prod1;
    }
};