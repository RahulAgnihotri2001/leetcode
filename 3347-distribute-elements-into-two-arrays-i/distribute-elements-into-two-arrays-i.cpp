class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int id1=0;
        int id2=0;
        int idx=2;
        while(idx<nums.size()){
            if(arr1[id1]>arr2[id2]){
                arr1.push_back(nums[idx]);
                id1++;
            }
            else{
                arr2.push_back(nums[idx]);
                id2++;
            }
            idx++;
        }
        for(int i=0;i<arr2.size();i++){
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};