class Solution {
public:
    int minAddToMakeValid(string s) {
        int sa=0;
        int answer=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                sa++;
            }
            else{
                sa--;
                if(sa<0){
                    answer++;
                    sa=0;
                }
            }
        }
        sa=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')'){
                sa++;
            }
            else{
                sa--;
                if(sa<0){
                    answer++;
                    sa=0;
                }
            }
        }
        return answer;
    }
};