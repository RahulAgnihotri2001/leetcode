class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> vec1(26,0);
        vector<int> vec2(26,0);
        for(int i=0;i<s.length();i++){
            vec1[s[i]-'a']++;
            vec2[t[i]-'a']++;
        }
        int answer=0;
        for(int i=0;i<26;i++){
            if(vec2[i]>vec1[i]){
                answer+=vec2[i]-vec1[i];
            }
        }
        return answer;
    }
};