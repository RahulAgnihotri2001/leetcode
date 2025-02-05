class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int ans=0;
        if(s1.length()!=s2.length())
            return false;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                ans++;
            }
        }
        if(ans==2 || ans==0){
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            if(s1!=s2){
                return false;
            }
            return true;
        }
        return false;
    }
};