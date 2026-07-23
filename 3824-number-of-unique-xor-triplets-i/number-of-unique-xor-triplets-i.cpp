class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // eXCEPTION TILL 3
        if(nums.size()==1 || nums.size()==2){
            return nums.size();
        }
        int count=0;
        int x=nums.size();
        while(x>1){
            x=x/2;
            count++;
        }
        count++;
        return pow(2,count);
        

    }
};