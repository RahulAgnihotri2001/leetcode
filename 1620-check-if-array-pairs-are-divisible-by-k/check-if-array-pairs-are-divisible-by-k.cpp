class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
           int x=arr[i]%k;
           if(x<0){
            x=x+k;
           }
            mp[x]++;
        }
        for(auto it:mp){
            cout<<it.first<<" : "<<it.second<<endl;
            if(it.second == mp[(k-it.first)%k]){
                if(it.first==(k-it.first)%k && it.second%2!=0){
                    return false;
                }
                mp[it.first]=0;
                mp[k-it.first]=0;
            }
            else if(it.second == 0 ){
                continue;
            }
            else{
                cout<<it.first<<endl;
                return false;
            }
        }
        return true;
    }
};