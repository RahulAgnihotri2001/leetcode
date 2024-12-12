class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int i=0;i<gifts.size();i++){
            pq.push(gifts[i]);
        }
        long long answer=0;
        for(int i=0;i<k;i++){
            int x=pq.top();
            pq.pop();
            pq.push(sqrt(x));
        }
        while(!pq.empty()){
            answer=answer+pq.top();
            pq.pop();
        }
        return answer;
    }
};