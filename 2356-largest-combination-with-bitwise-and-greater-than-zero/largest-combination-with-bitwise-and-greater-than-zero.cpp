class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> store;
        for(int i=0;i<32;i++){
            store.push_back(0);
        }
        for(int i=0;i<candidates.size();i++){
            int y=0;
            int x=candidates[i];
            while(x){
                if(x&1!=0){
                    store[y]++;
                }
                x=x>>1;
                y++;
            }
        }
        int answer=0;
        for(int i=0;i<store.size();i++){
            answer=max(answer,store[i]);
        }
        return answer;
    }
};