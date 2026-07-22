class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> temp;
        int sum = 0;
        for(int i=0;i<gas.size();i++){
            temp.push_back(gas[i]-cost[i]);
            sum= sum+gas[i]-cost[i];
        }
        if(sum<0){
            return -1;
        }
        int total=0;
        int ans=0;
        for(int i=0;i<temp.size();i++){
            total+=temp[i];
            if(total<0){
                total=0;
                ans=i+1;
            }
        }
        return ans;
            
    }
};