class Solution {
public:

    void dfs(vector<vector<int>>& land,int i,int j,int &maxrow,int &maxcol){
        land[i][j]=2;
        maxrow=max(i,maxrow);
        maxcol=max(j,maxcol);
        if(i+1<land.size() && land[i+1][j]==1){
            dfs(land,i+1,j,maxrow,maxcol);
        }
        if(j+1<land[0].size() && land[i][j+1]==1){
            dfs(land,i,j+1,maxrow,maxcol);
        }
        return;
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        // can do dfs on first found and that start point will be first part of answer
        vector<vector<int>> answer;
        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[0].size();j++){
                if(land[i][j]==1){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    int maxrow=i;
                    int maxcol=j;
                    dfs(land,i,j,maxrow,maxcol);
                    temp.push_back(maxrow);
                    temp.push_back(maxcol);
                    answer.push_back(temp);
                }
            }
        }
        return answer;
    }
};