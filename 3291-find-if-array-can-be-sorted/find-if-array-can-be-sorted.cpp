class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        // Store final sorted position in a map
        // Create another array containing only the count of set bit
        // from current position to final position every index should have same count of set bit
        vector<int> temp1=nums;
        sort(temp1.begin(),temp1.end());
        map<int,int> mp;
        for(int i=0;i<temp1.size();i++){
            mp[temp1[i]]=i;
        }
        vector<int> setCount;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int count=0;
            while(x!=0){
                if(x&1==1){
                    count++;
                }
                x=x>>1;
            }
            setCount.push_back(count);
        } 
        for(int i=0;i<nums.size();i++){
            int finalpos=mp[nums[i]];
            if(finalpos==i){
                continue;
            }
            if(finalpos>i){
                for(int k=i;k<=finalpos;k++){
                    if(setCount[k]!=setCount[i]){
                        return false;
                    }
                }
            }
            else{
                for(int k=i;k>=finalpos;k--){
                    if(setCount[k]!=setCount[i]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};