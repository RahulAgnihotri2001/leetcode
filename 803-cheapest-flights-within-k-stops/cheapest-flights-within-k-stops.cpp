class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // make map directed
        map<int,vector<pair<int,int>>> mp;  // src,destination , dis
        for(int i=0;i<flights.size();i++){
            mp[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{src,0}});   // stops , src ,distance;
        vector<int> dist(n,1e9);
        dist[src]=0;
        while(!pq.empty()){
            pair<int,pair<int,int>> temp=pq.front();
            pq.pop();
            int node = temp.second.first;
            int distance=temp.second.second;
            int stop=temp.first;
            for(auto it : mp[node]){
                int des= it.first;
                int dis=it.second;
                if(dis+distance<dist[des]){
                    dist[des]=dis+distance;
                    if(stop+1<=k){
                    pq.push({stop+1,{des,dis+distance}});
                }
            }
                
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};