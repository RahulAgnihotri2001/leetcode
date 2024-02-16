class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>> vec;
        for(auto it: mp){
            vec.push_back({it.second,it.first});
        }
        sort(vec.begin(),vec.end());
        int index=0;
        while(k>0){
            if(vec[index].first<=k){
                k=k-vec[index].first;
                index++;
            }
            else{
                break;
            }
        }
        return vec.size()-index;
    }
};