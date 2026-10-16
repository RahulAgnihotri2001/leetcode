class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        reverse(piles.begin(),piles.end());
        int answer = 0;
        int a = piles.size()/3;
        for(int i=1;i<=2*a;i=i+2){
            answer = answer + piles[i];
        }
        return answer;
    }
};