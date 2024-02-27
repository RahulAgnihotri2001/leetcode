class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& group) {
        // starting with 0
        int index=0;
        vector<string> str1;
        int flag=0;
        while(index<group.size()){
            if(flag==0){
                while(index<group.size() && group[index]!=0){
                    index++;
                }
                if(index<group.size()){
                    str1.push_back(words[index]);
                    flag=1;
                    index++;
                }
            }
            else{
                while(index<group.size() && group[index]!=1){
                    index++;
                }
                if(index<group.size()){
                    str1.push_back(words[index]);
                    flag=0;
                    index++;
                }
            }
        }
        // starting with 1
        vector<string> str2;
        index=0;
        flag=1;
        while(index<group.size()){
            if(flag==1){
                while(index<group.size() && group[index]!=1){
                    index++;
                }
                if(index<group.size()){
                    str2.push_back(words[index]);
                    flag=0;
                    index++;
                }
            }
            else{
                while(index<group.size() && group[index]!=0){
                    index++;
                }
                if(index<group.size()){
                    str2.push_back(words[index]);
                    flag=1;
                    index++;
                }
            }
        }
        if(str1.size()>=str2.size()){
            return str1;
        }
        return str2;
    }
};