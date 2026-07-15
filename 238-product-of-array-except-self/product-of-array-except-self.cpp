class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> vec1;
        int a=1;
        for(int i=0;i<nums.size();i++){
            vec1.push_back(a);
            a=a*nums[i];
        }

        vector<int> vec2;
        a=1;
        for(int i=nums.size()-1;i>=0;i--){
            vec2.push_back(a);
            a=a*nums[i];
        }
        reverse(vec2.begin(),vec2.end());
        for(int i=0;i<vec1.size();i++){
            vec1[i]=vec1[i]*vec2[i];
        }
        return vec1;
    }
};