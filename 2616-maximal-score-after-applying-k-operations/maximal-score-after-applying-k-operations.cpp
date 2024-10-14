class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        long long answer=0;
        for(int i=0;i<k;i++){
            answer=answer+pq.top();
            int a=pq.top();
            pq.pop();
            a=(a+3-1)/3;
            pq.push(a);
        }
        return answer;
    }
};