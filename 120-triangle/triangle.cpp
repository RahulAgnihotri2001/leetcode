class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        // i th row have i+1 columns 
        // first cliumn in lower row have access only to first column in upper row 
        int a = tri.size();
        for(int i=1;i<a;i++){
            for(int j=0;j<=i;j++){
                int x= INT_MAX;
                int y = INT_MAX;
                if(j-1>=0){
                    x = tri[i-1][j-1];
                }
                if(j!=i){
                    y = tri[i-1][j];
                }
                tri[i][j] = tri[i][j]+min(x,y);
            }
        }
        int answer = INT_MAX;
        for(int i=0;i<tri[tri.size()-1].size();i++){
            answer = min(answer,tri[tri.size()-1][i]);
        }
        return answer;
    }
};