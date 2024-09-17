class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // Store all words in a single set
        vector<string> answer;
        map<string,int> mp;
        int index=0;
        string temp="";
        while(index<s1.length()){
            if(s1[index]==' '){
                mp[temp]++;
                temp="";
            }
            else{
                temp.push_back(s1[index]);
            }
            index++;
        } 
        mp[temp]++;
        temp="";
        index=0;
        while(index<s2.length()){
            if(s2[index]==' '){
                mp[temp]++;
                temp="";
            }
            else{
                temp.push_back(s2[index]);
            }
            index++;
        } 
        mp[temp]++;
        for(auto it:mp){
            if(it.second == 1){
                answer.push_back(it.first);
            }
        }
        return answer;
    }
};