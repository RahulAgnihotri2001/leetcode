class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // make a priority queue 
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<heights.size()-1;i++){
            if(heights[i]<heights[i+1]){
                pq.push(heights[i+1]-heights[i]);
            }
            if(pq.size()>ladders){
                if(pq.top()<=bricks){
                    bricks=bricks-pq.top();
                    pq.pop();
                }
                else{
                    return i;
                }
            }
        }
        return heights.size()-1;
    }
};