class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(),banned.end());
        int index=0;
        int sum=0;
        int count=0;
        for(int i=1;i<=n;i++){
            if(index<banned.size() && i==banned[index]){
                while(index+1<banned.size() && banned[index]==banned[index+1])
                    index++;
                index++;
            }
            else{
                sum=sum+i;
                if(sum>maxSum){
                    sum=sum-i;
                    break;
                }
                else{
                    count++;
                }
            }
        }
        cout<<sum<<endl;
        return count;
    }
};