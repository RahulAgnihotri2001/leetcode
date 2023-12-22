class Solution {
public:

    bool ispalin(int start,int end,string s){
        while(start<end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int flag=0;
        int start=0;
        int end=s.length()-1;
        while(start<end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                bool a=ispalin(start,end-1,s);
                bool b=ispalin(start+1,end,s);
                return a|b;
            }
        }
        return true;
    }
};