class Solution {
public:
    int minimumLength(string s) {
        vector<int> character(26,0);
        for(int i=0;i<s.length();i++){
            character[s[i]-'a']++;
        }
        int answer=0;
        for(int i=0;i<26;i++){
            if(character[i]==0){
                continue;
            }
            if(character[i]%2==1){
                answer++;
            }
            else{
                answer=answer+2;
            }
        }
        return answer;
    }
};