class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st;
            for(int j=0;j<nums.size();j++){
                for(int k=j;k<nums.size();k++){
                    int a = nums[j]^nums[k];
                    st.insert(a);
                }
            }
            unordered_set<int> st2;
            for(int i=0;i<nums.size();i++){
                for(auto it = st.begin();it!=st.end();it++){
                    st2.insert(nums[i]^ *it);
                }
            }

        return st2.size();
    }
    
};