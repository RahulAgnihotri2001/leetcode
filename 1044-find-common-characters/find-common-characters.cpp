class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> track(words.size(),vector<int>(26,0));
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                track[i][words[i][j]-'a']++;
            }
        }
        vector<string> answer;
        for(int i=0;i<26;i++){
            int ma=INT_MAX;
            for(int j=0;j<words.size();j++){
                ma=min(track[j][i],ma);
            }
            for(int k=0;k<ma;k++){
                string temp;
                temp.push_back('a'+i);
                answer.push_back(temp);
            }
        }
        return answer;

    }
};