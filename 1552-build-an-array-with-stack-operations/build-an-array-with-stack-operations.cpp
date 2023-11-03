class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int index=0;
        int ind=1;
        vector<string> ans;
        string a="Push";
        string b="Pop";
        while(index<target.size()){
            if(ind<target[index]){
                ans.push_back(a);
                 ans.push_back(b);
            }
            else{
                ans.push_back(a);
                index++;
            }
            ind++;
        }
        return ans;
    }
};