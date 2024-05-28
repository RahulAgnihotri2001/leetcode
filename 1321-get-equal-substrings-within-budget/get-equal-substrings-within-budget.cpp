class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> arr;
        for(int i=0;i<s.length();i++){
            int a=abs(s[i]-t[i]);
            arr.push_back(a);
        }
        int start=0;
        int end=0;
        int temp=0;
        int answer=0;
        while(end<arr.size()){
            if(start==end && arr[end]>maxCost){
                end++;
                start=end;
                temp=0;
            }
            else if(temp+arr[end]<=maxCost){
                temp=temp+arr[end];
                end++;
                answer=max(answer,end-start);
            }
            else{
                temp=temp+arr[end];
                while(temp>maxCost){
                    temp=temp-arr[start];
                    start++;
                }
                answer=max(answer,end-start);
                end++;
            }
        }
        return answer;

    }
};