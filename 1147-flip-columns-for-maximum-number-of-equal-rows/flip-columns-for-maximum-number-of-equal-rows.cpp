class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string,int> mp;
        int answer=0;
        for(int i=0;i<matrix.size();i++){
            string string1="";
            string string2="";
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==1){
                    string1.push_back('1');
                    string2.push_back('0');
                }
                else{
                    string1.push_back('0');
                    string2.push_back('1');
                }
            }
            mp[string1]++;
            mp[string2]++;
        }
        for(auto it: mp){
            answer=max(answer,it.second);
        }
        return answer;
    }
};