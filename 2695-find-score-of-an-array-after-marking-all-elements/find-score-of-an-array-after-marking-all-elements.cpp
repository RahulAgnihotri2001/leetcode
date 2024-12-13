class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        set<int> index;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        long long answer=0;
        for(int i=0;i<nums.size();i++){
            int a=pq.top().first;
            int b=pq.top().second;
            if(index.find(b)==index.end()){
                answer=answer+a;
                index.insert(b);
                if(b>0){
                    index.insert(b-1);
                }
                if(b<nums.size()-1){
                    index.insert(b+1);
                }
            }
            pq.pop();
        }
        return answer;
    }
};