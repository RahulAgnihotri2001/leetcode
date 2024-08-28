class Solution {
public:

    bool dfs(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(i>=grid1.size() || j>=grid1[0].size() || i<0 || j<0){
            return true;
        }
        if(grid2[i][j]==1 && grid1[i][j]!=1){
            return false;
        }
        if(grid1[i][j]==1 && grid2[i][j]==1){
            grid1[i][j]=2;
            grid2[i][j]=2;
            bool temp=true;
            temp=temp & dfs(i+1,j,grid1,grid2);
            temp=temp & dfs(i-1,j,grid1,grid2);
            temp=temp & dfs(i,j-1,grid1,grid2);
            temp=temp & dfs(i,j+1,grid1,grid2);
            return temp;
        }
        return true;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // Kind of DFS and traversal in both the grids
        int m = grid1.size();
        int n=grid1[0].size();
        int answer=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid1[i][j]==1 && grid2[i][j]==1){
                    if(dfs(i,j,grid1,grid2)){
                        answer++;
                    }  // By reference;
                }
            }
        }
        return answer;
    }
};