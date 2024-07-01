class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int var=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==1){
                var++;
                if(var>=3){
                    return true;
                }
            }
            else{
                var=0;
            }
        }
        return false;
    }
};