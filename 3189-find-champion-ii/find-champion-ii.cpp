class Solution {
public:

    void dfs(int node,map<int,vector<int>> &mp, unordered_set<int> &se, stack<int> &st){
        se.insert(node);
        for(auto it : mp[node]){
            if(se.find(it)==se.end()){
                dfs(it,mp,se,st);
            }
        }
        st.push(node);
    }

    int dfs1(int node,unordered_set<int> &se, map<int,vector<int>> &mp){
        int ans=0;
        se.insert(node);
        for(auto it: mp[node]){
            if(se.find(it)==se.end()){
                ans=ans+dfs1(it,se,mp)+1;

            }
        }
        return ans;
    }

    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set<int> se;
        map<int,vector<int>> mp;
        stack<int> st;
        for(int i=0;i<edges.size();i++){
                mp[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<n;i++){
            if(se.find(i)==se.end())
                dfs(i,mp,se,st);
        }
        se.clear();
        int x=st.top();
        cout<<x<<endl;
        int count=dfs1(x,se,mp)+1;
        cout<<count<<endl;
        if(count==n){
            return x;
        }
        return -1;
    }
};