class Solution {
public:
    int minOperations(string s) {
        int a=0;
        int flag=0;
        for(int i=0;i<s.length();i++){
            if(flag==0){
                if(s[i]!='0'){
                    a++;
                }
                flag=1;
            }
            else{
                if(s[i]!='1'){
                    a++;
                }
                flag=0;
            }
        }
        int b=0;
        flag=1;
        for(int i=0;i<s.length();i++){
            if(flag==0){
                if(s[i]!='0'){
                    b++;
                }
                flag=1;
            }
            else{
                if(s[i]!='1'){
                    b++;
                }
                flag=0;
            }
        }
        return min(a,b);
    }
};