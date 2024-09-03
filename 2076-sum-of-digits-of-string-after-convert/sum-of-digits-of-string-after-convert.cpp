class Solution {
public:

    // We need a function to get sum of all digits int the number
    int fun(int a){
        int temp=0;
        while(a!=0){
            temp=temp+ a%10;
            a=a/10;
        }
        return temp;
    }



    int getLucky(string s, int k) {
        // Convert string into k=1 output
        int sum=0;
        for(int i=0;i<s.length();i++){
            int temp=s[i]-'a'+1;
            sum=sum+temp%10;
            temp=temp/10;
            if(temp>0){
                sum=sum+temp;
            }
        }
        cout<<sum;
        if(k==1){
            return sum;
        }
        k--;
        while(sum>9 && k>0){
            sum=fun(sum);
            k--;
        }
        return sum;
    }
};