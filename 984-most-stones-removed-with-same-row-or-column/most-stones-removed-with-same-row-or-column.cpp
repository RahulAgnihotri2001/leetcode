class Solution {
public:

    void dfs(int i,int j,set<pair<int,int>> &visited,map<int,vector<pair<int,int>>> &x,map<int,vector<pair<int,int>>> &y ){
        // Traversing through the map of x coordinate 
        for(auto it:x[i]){
            if(visited.find({it.first,it.second})==visited.end()){
                visited.insert({it.first,it.second});
                dfs(it.first,it.second,visited,x,y);
            }
        }
        // Traversing through map of y coordinate
        for(auto it:y[j]){
            if(visited.find({it.first,it.second})==visited.end()){
                visited.insert({it.first,it.second});
                dfs(it.first,it.second,visited,x,y);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        //  Implementing dfs 
        // Storing in map of x and y
        map<int,vector<pair<int,int>>> x;
        map<int,vector<pair<int,int>>> y;
        for(int i=0;i<stones.size();i++){
            x[stones[i][0]].push_back({stones[i][0],stones[i][1]});
            y[stones[i][1]].push_back({stones[i][0],stones[i][1]});
        }
        //  Keeping a track of visited coordinates
        set<pair<int,int>> visited;
        int count=0;
        //  Now traversing theough the stones array and doing dfs on unvisited coordinates
        for(int i=0;i<stones.size();i++){
            if(visited.find({stones[i][0],stones[i][1]}) == visited.end()){
                visited.insert({stones[i][0],stones[i][1]});
                dfs(stones[i][0],stones[i][1],visited,x,y);
                count++;
            }
        }
        return stones.size()-count;
    }
};