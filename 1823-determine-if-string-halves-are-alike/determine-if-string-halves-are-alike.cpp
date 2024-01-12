class Solution {
public:
    bool halvesAreAlike(string s) {
        int count=0;
        unordered_set<char> st;
        st.insert('A');
        st.insert('a');
        st.insert('E');
        st.insert('O');
        st.insert('I');
        st.insert('U');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        for(int i=0;i<s.length();i++){
            if(st.find(s[i])!=st.end()){
                count++;
            }
        }
        if(count%2==1){
            return false;
        }
        count=count/2;
        for(int i=0;i<s.length()/2;i++){
             if(st.find(s[i])!=st.end()){
                count--;
            }
        }
        if(count==0){
            return true;
        }
        return false;
    }
};