class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time =customers[0][0];
        double ans=0;
        for(int i=0;i<customers.size();i++){
            if(time>customers[i][0]){
                time=time+customers[i][1];
                ans=ans+(time-customers[i][0]);
            }
            else{
                ans=ans+(customers[i][1]);
                time=customers[i][0]+customers[i][1];
            }
        }
        double x=customers.size();
        return ans/x;
    }
};