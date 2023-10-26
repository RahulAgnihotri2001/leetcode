class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        map<int,long long> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=1;
        }
        for(int i=1;i<arr.size();i++){
            for(int j=0;j<i;j++){
                int x=arr[i]/arr[j];
                if(arr[i]%arr[j]==0 && mp[x]!=0){
                    mp[arr[i]]=(mp[arr[i]]+(mp[arr[j]]*mp[x]))%1000000007;
                    // cout<<"hello"<<endl;
                }
            }
        }
        int answer=0;
        for(auto it: mp){
            answer=(answer+it.second)%1000000007;;
        }
        return answer;
    }
};