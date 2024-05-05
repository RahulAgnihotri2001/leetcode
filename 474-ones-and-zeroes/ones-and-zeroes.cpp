class Solution {
public:

    

    int findMaxForm(vector<string>& strs, int m, int n) {
        // Replace every string with count of 0 and 1 init
        // func(m left , n left ,ith index)
        vector<pair<int,int>> vec;
        for(int i=0;i<strs.size();i++){
            int a=0,b=0;
            for(int j=0;j<strs[i].length();j++){
                if(strs[i][j]=='0'){
                    a++;
                }
                else{
                    b++;
                }
            }
            vec.push_back({a,b});
        }
        int x=m; // Zero left 
        int y=n; // One Left
        int index=0;
         vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        int answer=func(m,n,index,vec,dp);
        return answer;
    }

    int func(int m,int n,int index,vector<pair<int,int>> &vec,vector<vector<vector<int>>> &dp){
        if(index>=vec.size()){
            return 0;
        }
        if(m==0 && n==0){
            return 0;
        }
        if(dp[index][m][n] != -1) return dp[index][m][n];
        int answer1=0,answer2=0;
        if(vec[index].first<=m && vec[index].second<=n){
            answer1=1+func(m-vec[index].first,n-vec[index].second,index+1,vec,dp);
        }
        answer2=func(m,n,index+1,vec,dp);
        dp[index][m][n]=max(answer1,answer2);
        return  dp[index][m][n];
    }
};