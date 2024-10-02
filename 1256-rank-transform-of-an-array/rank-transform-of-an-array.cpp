class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0){
            return arr;
        }
        vector<int> temp;
        for(int i=0;i<arr.size();i++){
            temp.push_back(arr[i]);
        }
        sort(temp.begin(),temp.end());
        int count=1;
        map<int,int> mp;
        mp[temp[0]]=count;
        for(int i=1;i<temp.size();i++){
            if(temp[i]!=temp[i-1]){
                count++;
            }
            mp[temp[i]]=count;
        }
        for(int i=0;i<arr.size();i++){
            temp[i]=mp[arr[i]];
        }
        return temp;

    }
};