class TimeMap {
public:

    unordered_map<string,vector<pair<int,string>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<int,string> pr;
        pr.first = timestamp;
        pr.second = value;
        mp[key].push_back(pr);
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)== mp.end()){
            return "";
        }
        if(mp[key][0].first>timestamp){
            return "";
        }
        int start = 0;
        int end = mp[key].size()-1;
        while(start<end){
            int mid = (start+end)/2;
            if(mp[key][mid].first > timestamp){
                end = mid;
            }
            else{
                start= mid+1;
            }
        }
        if(mp[key][start].first > timestamp){
            return mp[key][start-1].second;
        }
        return mp[key][start].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */