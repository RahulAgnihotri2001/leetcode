class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        map<char,char> mp;
        set<char> st;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end()){
                if(st.find(t[i])==st.end()){
                mp[s[i]]=t[i];
                st.insert(t[i]);
                }
                else{
                    return false;
                }
            }
            else{
                if(mp[s[i]]!=t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};