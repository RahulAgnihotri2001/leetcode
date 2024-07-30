class Solution {
public:
    int minimumDeletions(string s) {
        int counta=0;
        vector<int> vec;
        for(int i=0;i<s.length();i++){
            vec.push_back(counta);
            if(s[i]=='a')
                counta++;
        }
        counta=0;
        for(int i=s.length()-1;i>=0;i--){
            vec[i]=vec[i]+counta;
            if(s[i]=='b'){
                counta++;
            }
        }
        int answer=0;
        for(int i=0;i<vec.size();i++){
            answer=max(answer,vec[i]+1);
        }
        return s.length()-answer;

    }
};