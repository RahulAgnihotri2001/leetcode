class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> vec1;
        int p=1;
        for(int i=0;i<nums.size();i++){
            vec1.push_back(p);
            p=p*nums[i];
        }
        p=1;
        for(int i=nums.size()-1;i>=0;i--){
            vec1[i]=vec1[i]*p;
            p=p*nums[i];
        }
        return vec1;
    }
};