class Solution {
public:
     int answer=0;
    void DFS(int i , int j ,vector<vector<char>>& grid, vector<vector<int>> &track){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()){
            return;
        }
        if(track[i][j]==1){
            return;
        }
        if(grid[i][j]=='1'){
            track[i][j]=1;
            DFS(i-1,j,grid,track);
            DFS(i+1,j,grid,track);
            DFS(i,j-1,grid,track);
            DFS(i,j+1,grid,track);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
       
        vector<vector<int>> track(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    if(track[i][j]==0){
                            answer=answer+1;
                            DFS(i,j,grid,track);
                    }
                }
                
            }
        }
        return answer;
    }
};