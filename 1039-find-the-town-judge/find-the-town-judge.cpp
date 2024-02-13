class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
            vector<int> vec(n+1,0);
            for(auto it:trust){
                vec[it[1]]++;
                vec[it[0]]--;
            }
            for(int i=1;i<vec.size();i++){
                if(vec[i]==n-1){
                    return i;
                }
            }
        return  -1;
    }
};