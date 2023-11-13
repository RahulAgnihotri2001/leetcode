class Solution {
public:
    string sortVowels(string s) {
        string t;
        vector<int> vec;
        set<char> st;
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
        st.insert('a');
         st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        for(int i=0;i<s.length();i++){
            if(st.find(s[i])!=st.end()){
                vec.push_back(s[i]);
            }
        }
        sort(vec.begin(),vec.end());
        int j=0;
        for(int i=0;i<s.length();i++){
            if(st.find(s[i])!=st.end()){
                t.push_back(vec[j]);
                j++;
            }
            else{
                t.push_back(s[i]);
            }
        }
        return t;
    }
};