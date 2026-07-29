class Solution {
public:
    int numTrees(int n) {
        // Catalan Number;
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        int ans = catalan(n,dp);
        return ans;
    }

    int catalan(int n, vector<int> &dp){
        if(dp[n]!=-1){
            return dp[n];
        }
        int answer=0;
        for(int i=0;i<n;i++){
            answer = answer + catalan(i,dp)*catalan(n-1-i,dp);
        }
        dp[n]= answer;
        return dp[n];
    }

};