class Solution {
public:

    // static bool fun(vector<int> &a,vector<int> &b){
    //     return a[1]<b[1];
    // }

    static bool fun(vector<int> &a, vector<int> &b){
        if(a[0]<b[0]){
            return true;
        }
        if(a[0]>b[0]){
            return false;
        }
        return a[1]>b[1];
    }


    vector<int> frequencySort(vector<int>& nums) {
        // I can sort a vector pair 1. By map  2. By array of size 200
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> vec;
        for(auto it:mp){
            vector<int> temp;
            temp.push_back(it.second);
            temp.push_back(it.first);
            vec.push_back(temp);
        }
        sort(vec.begin(),vec.end(),fun);
        vector<int> answer;
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[i][0];j++)
                answer.push_back(vec[i][1]);
        }
        return answer;
    }
};