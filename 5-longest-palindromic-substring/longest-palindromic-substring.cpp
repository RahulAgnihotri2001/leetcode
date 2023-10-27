class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int t[n][n];
        int ma=1,a=0,b=0;
        string ans="";
        memset(t,0,sizeof(t));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==j){
                    t[i][j]=1;
                }
                else if(i==j-1 && s[i]==s[j]){
                    t[i][j]=1;
                    int x=2;
                    cout<<"x is "<<x<<endl;
                    if(x>ma){
                        ma=x;
                        a=i;
                        b=j;
                    }
                }
            }
        }
        for(int i=n-3;i>=0;i--){
            for(int j=i+2;j<n;j++){
                    if(s[i]==s[j] && t[i+1][j-1]==1){
                        t[i][j]=1;
                        int x=j-i+1;
                        if(x>ma){
                        ma=x;
                            cout<<"x is "<<x<<endl;
                        a=i;
                        b=j;
                        }
                    }
                }
            }
        for(int i=a;i<=b;i++){
            ans.push_back(s[i]);
        }
        return ans;
    }
};