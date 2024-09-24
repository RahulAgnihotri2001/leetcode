class Solution {
public:

    int func(string s1,string s2){
        int temp=0;
        int i=0,j=0;
        while(i<s1.length() && j<s2.length()){
            if(s1[i]==s2[j]){
                temp++;
                i++;
                j++;
            }
            else{
                return temp;
            }
        }
        return temp;
    }


    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        vector<string> ar1;
        vector<string> ar2;
        for(int i=0;i<arr1.size();i++){
            ar1.push_back(to_string(arr1[i]));
        }
        for(int i=0;i<arr2.size();i++){
            ar2.push_back(to_string(arr2[i]));
        }
        sort(ar1.begin(),ar1.end());
        sort(ar2.begin(),ar2.end());
        int i=0;
        int j=0;
        int answer=0;
        while(i<ar1.size()&& j<ar2.size()){
            answer=max(answer,func(ar1[i],ar2[j]));
            if(ar1[i]>ar2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return answer;
    }
};