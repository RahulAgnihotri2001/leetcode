class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        int start=0;
        int end=0;
        map<char,int> mp;
        int answer=1;
        mp[s[end]]++;
        end++;
        // cout<<'.';
        while(end<s.length()){
            if(mp[s[end]]<1){
                mp[s[end]]++;
                end++;
                // cout<<'.';
            }
            else{
                while(mp[s[end]]>=1){
                    mp[s[start]]--;
                    start++;
                    // cout<<'/';
                }
                mp[s[end]]++;
                end++;
                //cout<<'.';
            }
            answer=max(answer,end-start);
        }
        return answer;
    }
};