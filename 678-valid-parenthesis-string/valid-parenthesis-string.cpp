class Solution {
public:
    bool checkValidString(string s) {
        // doing it using dp
        vector<int> open(s.length());
        vector<int> close(s.length());
        int temp=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                temp++;
            }
            open[i]=temp;
            //cout<<temp<<", ";
        }
   // cout<<endl;
        temp=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')'){
                temp++;
            }
            close[i]=temp;
        }
        
        //cout<<endl;
        temp=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                temp++;
                if(temp<=open[i]){
                    s[i]='.';
                }
                else{
                    temp--;
                }
            }
        }
        temp=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='('){
                temp++;
                if(temp<=close[i]){
                    s[i]='.';
                }
                else{
                    temp--;
                }
            }
        }
        //cout<<endl;
        //cout<<s<<endl;
        // Now deling with *
        temp=0;  //here temp is count of *
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                temp++;
            }
            if(s[i]==')'){
                if(temp==0){
                    return false;
                }
                else{
                    temp--;
                    s[i]='.';
                }
            }
        }
        temp=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='*'){
                temp++;
            }
            if(s[i]=='('){
                if(temp==0){
                    return false;
                }
                else{
                    temp--;
                    s[i]='.';
                }
            }
        }
        for(int i=0;i<s.length();i++){
            if(s[i]==')' || s[i]=='('){
                return false;
            }
        }
        return true;
    }
};