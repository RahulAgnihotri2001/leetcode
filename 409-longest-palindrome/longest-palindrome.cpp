class Solution {
public:
    int longestPalindrome(string s) {
        if(s.length()==1){
            return 1;
        }
        map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int countOdd=0;
        for(auto &it :mp){
            if(it.second%2==1){
                countOdd++;
            }
        }
        int n=s.length();
        if(countOdd>0){
            n=n-countOdd+1;
        }
        return n;
    }
};