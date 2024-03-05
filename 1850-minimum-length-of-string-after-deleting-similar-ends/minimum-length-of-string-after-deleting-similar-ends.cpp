class Solution {
public:
    int minimumLength(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<end){
            if(s[start]!=s[end]){
                break;
            }
            while(start+1<s.length() && s[start]==s[start+1] && start+1<end ){
                start++;
            }
            while(end-1>=0 && s[end]==s[end-1] && end-1>start){
                end--;
            }
            end--;
            start++;

        }
        if(start>end){
            return 0;
        }
        if(start==end){
            return 1;
        }
        return end-start+1;
    }
};