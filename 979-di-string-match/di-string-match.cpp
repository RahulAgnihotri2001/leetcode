class Solution {
public:
    vector<int> diStringMatch(string s) {
        int start=0;
        int end=s.length();
        vector<int> answer;
        for(int i=0;i<s.length();i++){
            if(s[i]=='I'){
                answer.push_back(start);
                start++;
            }
            else{
                answer.push_back(end);
                end--;
            }
        }
        answer.push_back(start);
        return answer;
    }
};