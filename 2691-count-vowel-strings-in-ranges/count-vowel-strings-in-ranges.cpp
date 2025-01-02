class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> temp;
        int count=0;
        set<char>  st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        for(int i=0;i<words.size();i++){
            if(st.find(words[i][0])!=st.end() && st.find(words[i][words[i].length()-1])!=st.end()){
                count++;
            }
            temp.push_back(count);
        }
        vector<int> answer;
        for(int i=0;i<queries.size();i++){
            int a;
            if(queries[i][0]!=0){
                a=temp[queries[i][1]]-temp[queries[i][0]-1];
            }
            else{
                if(temp[0]==1){
                    a=temp[queries[i][1]]-temp[queries[i][0]]+1;
                }

                else{
                    a=temp[queries[i][1]]-temp[queries[i][0]];
                }
            }
            answer.push_back(a);
        }
        return answer;
    }
};