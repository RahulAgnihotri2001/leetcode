class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<pair<int,int>> rows;
        vector<pair<int,int>> col;
        // Traversing theough all the rows 0ne by one 
        int total_count=0;
        for(int i=0;i<grid.size();i++){
            int count=0;
            int location=-1;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    count++;
                    total_count++;
                    if(count==1){
                        location=j;
                    }
                    else{
                        location=-1;
                    }
                }
            }
            rows.push_back({count,location});
        }
        // Doing same for the columns 
        for(int i=0;i<grid[0].size();i++){
            int count=0;
            int location=-1;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==1){
                    count++;
                    if(count==1){
                        location=j;
                    }
                    else{
                        location=-1;
                    }
                }
            }
            col.push_back({count,location});
        }
        // going through all the columns and counting single server;
        int ss=0;
        for(int i=0;i<rows.size();i++){
            if(rows[i].first==1 && col[rows[i].second].first==1){
                ss++;
            }
        }
        return total_count-ss;
    }
};