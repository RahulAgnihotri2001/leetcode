class Solution {
public:
    int twoEggDrop(int n) {
        if(n<=2){
            return n;
        }
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;

        return fun(n,dp);
    }
    int fun(int n, vector<int>&dp){
        if(dp[n]!=-1){
            return dp[n];
        }
        int answer = INT_MAX;
        for(int i=1;i<n;i++){
            answer = min(answer, 1+max(i-1,fun(n-i,dp)));
        }
        dp[n]= answer;
        return dp[n];

    }
};