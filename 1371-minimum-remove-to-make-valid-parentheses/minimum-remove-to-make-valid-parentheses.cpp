class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> countstart(s.length());
        int temp=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
               temp++; 
            }
            countstart[i]=temp;
        }
        temp=0;
        vector<int> countback(s.length());
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')'){
               temp++; 
            }
            countback[i]=temp;
        }
        temp=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
               temp++; 
               if(temp>countstart[i]){
                s[i]='*';
                temp--;
               }
            }
        }

        temp=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='('){
               temp++; 
               if(temp>countback[i]){
                s[i]='*';
                temp--;
               }
            }
        }
        string answer="";
        for(int i=0;i<s.length();i++){
            if(s[i]!='*'){
                answer.push_back(s[i]);
            }
        }
        return answer;
    }
};