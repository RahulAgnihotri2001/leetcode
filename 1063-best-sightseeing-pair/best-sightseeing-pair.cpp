class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int> temp;
        int answer=INT_MIN;
        for(int i=0;i<values.size();i++){
            temp.push_back(values[i]-i);
        }
        int ma=temp[temp.size()-1];
        for(int i=values.size()-2;i>=0;i--){
            answer=max(answer,values[i]+i+ma);
            ma=max(ma,temp[i]);
        }
        return answer;
    }
};