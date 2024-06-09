class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(int i=0;i<k;i++){
            mp[i]=0;
        }
        mp[0]++;
        int ans=0;
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            sum=sum%k;
            if(sum<0){
                sum=sum+k;
            }
            ans=ans+mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};