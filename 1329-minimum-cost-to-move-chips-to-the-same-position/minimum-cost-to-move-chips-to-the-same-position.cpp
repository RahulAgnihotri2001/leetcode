class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        // bring it to 0 & 1
        int zero=0;
        int one=0;
        for(int i=0;i<position.size();i++){
            if(position[i]%2==0){
                zero++;
            }
            else{
                one++;
            }
        }
        return min(one,zero);
    }
};