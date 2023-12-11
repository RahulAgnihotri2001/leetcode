class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        double n=arr.size();
        if(n==1){
            return arr[0];
        }
        double want=n/4.0;
        //cout<<"want is "<<want<<endl;
        int x=arr[0];
        int  count=1;
        for(int i=1;i<n;i++){
            if(arr[i]==x){
                count++;
                if(count>want){
                return x;
            }
            }
            else{
                count=1;
                x=arr[i];
            }
        }
        return x;
    }
};