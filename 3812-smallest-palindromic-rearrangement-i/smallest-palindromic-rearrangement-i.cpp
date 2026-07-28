class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.length()==1){
            return s;
        }
        vector<int> vec(26,0);
        for(int i=0;i<s.length();i++){
            vec[s[i]-'a']++;
        }
        string answer="";
        string temp ="";
        for(int i=0;i<26;i++){
            if(vec[i]%2==1){
                temp.push_back('a'+i);
                vec[i]--;
                break;
            }
        }
        // Inserting first time 
        for(int i=0;i<26;i++){
            if(vec[i]>1){
                int a = vec[i]/2;
                vec[i] = vec[i] - a;
                for(int j=0;j<a;j++){
                    answer.push_back('a'+i);
                }
            }
        }
        string half = answer;
        if(temp.length()>0){
            answer.push_back(temp[0]);
        }
        for(int i=half.length()-1;i>=0;i--){
            answer.push_back(half[i]);
        }

        return answer;
    }
};