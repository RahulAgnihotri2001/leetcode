class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string answer="";
        int index=0;
        int i=0;
        while(index<s.length()){
            if(i<spaces.size() && spaces[i]==index){
                answer.push_back(' ');
                i++;
                index--;
            }
            else{
                answer.push_back(s[index]);
            }
            index++;
        }
        return answer;
    }
};