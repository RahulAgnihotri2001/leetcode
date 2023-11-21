class Solution {
public:

    long reverse(int a){
        long ans=0;
        while(a!=0){
            ans=ans*10;
            int x=a%10;
            a=a/10;
            ans=ans+x;
        }
        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<long,int> mp;
        for(int i=0;i<nums.size();i++){
            long x= reverse(nums[i]);
            //cout<<x<<"/";
            long y= long(nums[i])-x;
            //cout<<y<<"**";
            mp[y]++;
        }
        long answer=0;
        long N=1000000007;
        for(auto it:mp){
            //1 to value-1 tak ka sum
            long x=long(it.second);
           if(x>1){
               answer=(answer+((x*(x-1))/2))%N;
           } 
        }
        return int(answer);
    }
};