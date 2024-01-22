class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[abs(nums[i])-1]=-1*nums[abs(nums[i])-1];
        }
        vector<int> vec;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                vec.push_back(i+1);
            }
        }
        cout<<vec[0]<<" // "<<vec[1]<<endl;
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i])==vec[0]){
                return vec;
            }
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};