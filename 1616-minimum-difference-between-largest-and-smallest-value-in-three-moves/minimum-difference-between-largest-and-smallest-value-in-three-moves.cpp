class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<=4){
            return 0;
        }
        int a= min((nums[nums.size()-4]-nums[0]),(nums[nums.size()-1]-nums[3]));
        int b= min((nums[nums.size()-3]-nums[1]),(nums[nums.size()-2]-nums[2]));
        int c=min((nums[nums.size()-2]-nums[2]),(nums[nums.size()-3]-nums[1]));
        return min(c,min(a,b));
        // This solution have a TC O(nlogn)
        // We only need 4 smallest and 4 largest element hence no need to sort entire array
        // Can find them in O(n) using heap of size 4, hence we most optimal solution TC O(n)
    }
};