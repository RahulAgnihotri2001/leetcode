class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> vec(s.length(),0);
        for(int i=0;i<shifts.size();i++){
            if(shifts[i][2]==0){
                if(shifts[i][0]-1>=0)
                vec[shifts[i][0]-1]=vec[shifts[i][0]-1]+1;
                vec[shifts[i][1]]=vec[shifts[i][1]]-1;
            }
            else{
                if(shifts[i][0]-1>=0)
                vec[shifts[i][0]-1]=vec[shifts[i][0]-1]-1;
                vec[shifts[i][1]]=vec[shifts[i][1]]+1;
            }
        }
        int count=0;
        for(int i=s.length()-1;i>=0;i--){
            count=count+vec[i];
            int x=s[i]-'a';
            x=x+count;
            while(x<0){
                x=x+26;
            }
            x=x%26;
            s[i]=char('a'+x);
        }
        return s;
    }
};