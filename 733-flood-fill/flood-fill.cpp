class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr1, int sc1, int color1) {
        // can be done in 2 ways 1. using stack(recursion) 2.Using Queue
        // doing using queue
        int color=image[sr1][sc1];
        queue<pair<int,int>> qu;
        vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));
        image[sr1][sc1]=color1;
        visited[sr1][sc1]=1;
        qu.push({sr1,sc1});
        while(!qu.empty()){
            pair<int,int> temp=qu.front();
            int sr=temp.first;
            int sc=temp.second;
            qu.pop();
            if(check(sr+1,sc,image,color,visited)){
                image[sr+1][sc]=color1;
                qu.push({sr+1,sc});
            }
            if(check(sr-1,sc,image,color,visited)){
                image[sr-1][sc]=color1;
                qu.push({sr-1,sc});
            }
            if(check(sr,sc+1,image,color,visited)){
                image[sr][sc+1]=color1;
                qu.push({sr,sc+1});
            }
            if(check(sr,sc-1,image,color,visited)){
                image[sr][sc-1]=color1;
                qu.push({sr,sc-1});
            }
        }
        return image;
    }
    bool check(int sr,int sc,vector<vector<int>>& image,int color,vector<vector<int>> &visited){
        if(sr>=0 && sr<image.size() && sc>=0 && sc<image[0].size() && image[sr][sc]==color && visited[sr][sc]==0){
            visited[sr][sc]=1;
            return true;
        }
        else{
            return false;
        }
    }
};