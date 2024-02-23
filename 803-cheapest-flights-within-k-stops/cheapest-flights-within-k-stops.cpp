class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flight, int src, int dst, int k) {
        // make priority queue with number of stops as deciding factor
        // will follow dijkestra
        // {stops{destination,price}};
        // converting v<v> it to graph


        map<int,vector<pair<int,int>>> mp;
        for(int i=0;i<flight.size();i++){
            mp[flight[i][0]].push_back({flight[i][1],flight[i][2]});
        }
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        while(!pq.empty()){
            int stops=pq.front().first;
            int source=pq.front().second.first;
            int fair=pq.front().second.second;
            pq.pop();
            for(auto it: mp[source]){
                int d=fair+it.second;
                if(d<dist[it.first]){
                    dist[it.first]=d;
                    if(stops+1<=k){
                        pq.push({stops+1,{it.first,d}});
                    }
                }
            }
        }
        if(dist[dst]!=1e9){
            return dist[dst];
        }
        return -1;
    }
};