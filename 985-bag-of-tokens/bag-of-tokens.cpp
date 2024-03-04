class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        // Spend base to get token with more value ie more power
        // Use this power to unlock small value of tokens
        int base=0;
        int ans=0;
        sort(token.begin(),token.end());
        int start=0;
        int end=token.size()-1;
        while(start<=end){
            if(power>=token[start]){
                power=power-token[start];
                start++;
                base++;
                ans=max(ans,base);
            }
            else if(base>0){
                power=power+token[end];
                end--;
                base--;
            }
            else{
                break;
            }
        }
        return ans;
    }
};