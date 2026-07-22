class Solution {
public:
    int lengthOfLastWord(string s) {
        int start=s.length()-1;
        while(start>=0){
            if(s[start]!=' '){
                break;
            }
            else{
                start--;
            }
        }
        int length=0;
        while(start>=0){
            if(s[start]==' '){
                break;
            }
            else{
                length++;
                start--;
            }
        }
        return length;
    }
};