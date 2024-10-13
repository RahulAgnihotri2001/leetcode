class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> index;
        int ma=INT_MIN;
        for(int i=0;i<nums.size();i++){
            index.push_back(0);
            pq.push({nums[i][0],i});
            ma=max(ma,nums[i][0]);
        }
        int a=ma;
        int b=pq.top().first;
        int ansa=a, ansb=b;
        int minindex=pq.top().second;
        // cout<<a<<" - "<<b;
        while(index[minindex]<nums[minindex].size()-1){
            pq.pop();
            index[minindex]++;
            pq.push({nums[minindex][index[minindex]],minindex});
            ma=max(ma,nums[minindex][index[minindex]]);
                a=ma;
                b=pq.top().first;
            
            if(ansa-ansb > a-b){
                ansa=a;
                ansb=b;
            }
            minindex=pq.top().second;
        }
        vector<int> answer;
        answer.push_back(ansb);
        answer.push_back(ansa);
        return answer;
    }
};