class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            int start=0;
            int end=words[i].length()-1;
            while(start<end){
                if(words[i][start]==words[i][end]){
                    start++;
                    end--;
                }
                else{
                    break;
                }
            }
            if(start>=end){
                return words[i];
            }
        }
        return "";
    }
};