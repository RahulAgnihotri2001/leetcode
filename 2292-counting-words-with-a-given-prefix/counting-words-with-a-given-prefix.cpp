class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int prefLength = pref.length();
        for (string word : words) {
            if (word.length() >= prefLength) {
                if (word.substr(0, prefLength) == pref) {
                    count++;
                }
            }
        }
        return count;
    }
};