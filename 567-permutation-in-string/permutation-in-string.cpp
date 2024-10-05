class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }
        vector<int> vec1(26,0);
        for(int i=0;i<s1.size();i++){
            vec1[s1[i]-'a']++;
        }
        vector<int> vec2(26,0);
        for(int i=0;i<s1.size();i++){
             vec2[s2[i]-'a']++;
        }
        int end=s1.size()-1;
        int start=0;
        while(end<s2.size()){
            if(vec1==vec2){
                return true;
            }
            vec2[s2[start]-'a']--;
            start++;
            end++;
            if(end<s2.size())
            vec2[s2[end]-'a']++;
        }
        return false;
    }
};