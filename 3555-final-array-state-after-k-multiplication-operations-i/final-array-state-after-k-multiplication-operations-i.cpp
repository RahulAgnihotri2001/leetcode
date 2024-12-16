class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        // make minheap
        // have to figure how to deal with starting element 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        for(int i=0;i<k;i++){
            int a=pq.top().first;
            int b=pq.top().second;
            pq.pop();
            a = a * multiplier;
            pq.push({a,b});
        }
        while(!pq.empty()){
            int a=pq.top().first;
            int b=pq.top().second;
            nums[b]=a;
            pq.pop();
        }
        return nums;
    }
};