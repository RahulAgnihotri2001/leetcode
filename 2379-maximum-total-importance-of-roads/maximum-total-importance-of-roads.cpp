class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int,vector<int>> mp;
        for(int i=0;i<roads.size();i++){
            mp[roads[i][0]].push_back(roads[i][1]);
            mp[roads[i][1]].push_back(roads[i][0]);
        }
        vector<long long> vec;
        for(auto it:mp){
            vec.push_back(it.second.size());
        }
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        long long answer=0;
         long long x=n;
        for(long long i=0;i<vec.size();i++){
           answer=answer+vec[i]*(x-i);

        }
        return answer;

    }
};