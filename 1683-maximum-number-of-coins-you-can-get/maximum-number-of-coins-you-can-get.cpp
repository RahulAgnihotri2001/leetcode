class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        reverse(piles.begin(),piles.end());
        int n=piles.size()/3;
        int x=1;
        int answer=0;
        for(int i=0;i<n;i++){
            answer=answer+piles[x];
            x=x+2;
        }
        return answer;
    }
};