class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        int answer=0;
        for(auto it : mp){
            int x=it.second;
            if(x>=3 && x!=4){
                while(x>=3 && x!=4){
                    answer=answer+1;
                    x=x-3;
                }
            }
            if(x==2){
               answer=answer+1;  
               x=0;
            }
            if(x==4){
                 answer=answer+2;  
               x=0;
            }
            if(x==1){
                return -1;
            }
        }
        return answer;
    }
};