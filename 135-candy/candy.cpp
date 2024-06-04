class Solution {
public:
    int candy(vector<int>& rat) {
        vector<int> answer(rat.size(),1);
        for(int i=1;i<rat.size();i++){
            if(rat[i]>rat[i-1]){
                answer[i]=answer[i-1]+1;
            }
        }
        for(int i=rat.size()-2;i>=0;i--){
            if(rat[i]>rat[i+1] && answer[i]<=answer[i+1]){
                answer[i]=answer[i+1]+1;
            }
        }
        int ans=0;
        for(int i=0;i<answer.size();i++){
            ans=ans+answer[i];
        }
        return ans;
    }
};