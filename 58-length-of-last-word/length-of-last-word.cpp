class Solution {
public:
    int lengthOfLastWord(string s) {
        int pos=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!=' '){
                pos++;
            }
            else if(s[i]==' ' && pos!=0){
                break;
            }
        }
        return pos;
    }
};