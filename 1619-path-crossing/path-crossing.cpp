class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> st;
        int x=0,y=0;
        st.insert({0,0});
        for(int i=0;i<path.length();i++){
            if(path[i]=='N'){
                y++;
            }
            else if(path[i]=='W'){
                x--;
            }
            else if(path[i]=='E'){
                x++;
            }
            else{
                y--;
            }
            if(st.find({x,y})!=st.end()){
                    return true;
            }
            st.insert({x,y});
        }
        return false;
    }
};