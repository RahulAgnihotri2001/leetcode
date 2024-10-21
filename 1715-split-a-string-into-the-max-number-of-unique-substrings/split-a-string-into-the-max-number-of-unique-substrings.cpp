class Solution {
public:
    // int maxUniqueSplit(string s) {
    //     set<string> mp;
    //     int end=0;
    //     int answer=0;
    //     string temp="";
    //     while(end<s.length()){
    //         temp.push_back(s[end]);
    //         if(mp.find(temp)==mp.end()){
    //             mp.insert(temp);
    //             answer++;
                
    //             temp="";
    //         }
    //         end++;
    //     }
    //     // if(temp.length()>0){
    //     //     answer--;
    //     // }
    //     return answer;
    // }
    int dp(int end, string temp, string &s, set<string> &mp) {
    // Base case: If we have processed the entire string
    if (end >= s.length()) {
        return 0;
    }

    temp.push_back(s[end]);  // Add current character to temp
    int b = dp(end + 1, temp, s, mp);  // Continue with the current substring
    
    int a = 0;
    if (mp.find(temp) == mp.end()) {  // Check if current substring is unique
        mp.insert(temp);  // Add the substring to the set
        a = 1 + dp(end + 1, "", s, mp);  // Start a new substring after the current one
        mp.erase(temp);  // Backtrack: remove the substring from the set
    }

    return max(a, b);  // Return the max of splitting or continuing
}


    // Lets go with a dp solution 
    int maxUniqueSplit(string s) {
        set<string> mp;
        int end=0;
        string temp="";
        return dp(end,temp,s,mp);
    }
};