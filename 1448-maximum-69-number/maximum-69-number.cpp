class Solution {
public:
    int maximum69Number (int num) {
        string str=to_string(num);
        for(int i=0;i<str.length();i++){
            if(str[i]=='6'){
                str[i]='9';
                break;
            }
        }
        /*
        for(int i=str.length()-1;i>=0;i--){
            if(str[i]=='9'){
                str[i]='6';
                break;
            }
        }
        */
        int x=stoi(str);
        return x;
    }
};