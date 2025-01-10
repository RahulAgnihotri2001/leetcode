class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> vec(26,0);

        for(int i=0;i<words2.size();i++){
            vector<int> temp(26,0);
            for(int j=0;j<words2[i].length();j++){
                temp[words2[i][j]-'a']++;
            }
            for(int j=0;j<26;j++){
                vec[j]=max(vec[j],temp[j]);
            }
        }
        vector<string> answer;
        for(int i=0;i<words1.size();i++){
            vector<int> temp(26,0);
            for(int j=0;j<words1[i].length();j++){
                temp[words1[i][j]-'a']++;
            }
            int flag=0;
            for(int j=0;j<26;j++){
                    if(vec[j]>temp[j]){
                        flag=1;
                        break;
                    }
            }
            if(flag==0){
                answer.push_back(words1[i]);
            }
        }
        return answer;
    }
};