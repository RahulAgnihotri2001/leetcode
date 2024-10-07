class Solution {
public:
    int minLength(string s) {
        string temp="";
        temp.push_back(s[0]);
        for(int i=1;i<s.length();i++){
            if(temp.length()>0 && s[i]=='B' && temp[temp.length()-1]=='A'){
                temp.pop_back();
            }
            else if(temp.length()>0 && s[i]=='D' && temp[temp.length()-1]=='C'){
                temp.pop_back();
            }
            else{
                temp.push_back(s[i]);
            }
        }
        cout<<temp;
        return temp.length();

    }
};