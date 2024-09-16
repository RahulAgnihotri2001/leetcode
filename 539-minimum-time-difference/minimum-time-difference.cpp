class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int answer=INT_MAX;
        for(int i=0;i<timePoints.size()-1;i++){
            int a= stoi(timePoints[i+1].substr(0,2))-stoi(timePoints[i].substr(0,2));
            int b= stoi(timePoints[i+1].substr(3,2))-stoi(timePoints[i].substr(3,2));
            answer=min(answer,(a*60+b));
        }
        int a= stoi(timePoints[timePoints.size()-1].substr(0,2))-stoi(timePoints[0].substr(0,2));
        int b= stoi(timePoints[timePoints.size()-1].substr(3,2))-stoi(timePoints[0].substr(3,2));
        int x=1440-(a*60+b);
        answer=min(answer,x);
        return answer;
    }
};