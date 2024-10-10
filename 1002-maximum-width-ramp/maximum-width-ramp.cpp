class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>> vec;
        for(int i=0;i<nums.size();i++){
            pair<int,int> temp={nums[i],i};
            vec.push_back(temp);
        }
        sort(vec.begin(),vec.end());
        vector<int> temp;
        int a=vec[0].second;
        temp.push_back(vec[0].second);
        for(int i=1;i<vec.size();i++){
            a=min(a,vec[i].second);
            temp.push_back(a);
        }
        int answer=0;
        for(int i=vec.size()-1;i>=0;i--){
            answer=max(answer,vec[i].second-temp[i]);
        }
        return answer;
    }
};