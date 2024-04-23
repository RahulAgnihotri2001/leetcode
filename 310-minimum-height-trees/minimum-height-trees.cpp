class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
        if(n == 1)
            return {0};
        vector<pair<int,int>> connectInfo(n);

        for(auto &edge : edges) {
            connectInfo[edge[0]].first += edge[1];
            ++connectInfo[edge[0]].second;
            connectInfo[edge[1]].first += edge[0];
            ++connectInfo[edge[1]].second;
        }

        vector<int> leaves;
        for(int i = 0; i < n; ++i) 
            if(connectInfo[i].second == 1)
                leaves.push_back(i);

        vector<int> ans;
        while(n > 2) {
            n -= leaves.size();
            ans.clear();
            for(int i = 0; i < leaves.size(); ++i) {
                connectInfo[connectInfo[leaves[i]].first].first -= leaves[i];
                if(--connectInfo[connectInfo[leaves[i]].first].second == 1)
                    ans.push_back(connectInfo[leaves[i]].first);
            }
            leaves = ans;
        }
        return leaves;
    }
};