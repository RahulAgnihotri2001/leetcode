class Solution {
public:

    void dfs(stack<int> &st,set<int> &se,vector<int> &answer, map<int,vector<int>> &mp){
        while(!st.empty()){
            int x=st.top();
            st.pop();
            for(auto it: mp[x]){
                if(se.find(it)==se.end()){
                    se.insert(it);
                    st.push(it);
                    answer.push_back(it);
                }
            }
        }
    }


    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Reverse th edirection of the link and do dfs from source
        map<int,vector<int>> mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>> answer;
        for(int i=0;i<n;i++){
            stack<int> st;
            st.push(i);
            set<int> se;
            se.insert(i);
            vector<int> temp;
            dfs(st,se,temp,mp);
            sort(temp.begin(),temp.end());
            answer.push_back(temp);
        }
        return answer;

    }
};