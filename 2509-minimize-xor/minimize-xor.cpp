class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // get number of set bit in num2
        int count=0;
        while(num2!=0){
            if(num2 & 1==1){
                count++;
            }
            num2=num2>>1;
        }
        cout<<count<<":::"<<endl;
        vector<int> temp(32,0);
        int i=0;
        while(num1!=0){
            if(num1 & 1==1){
                temp[i]=1;
            }
            num1=num1>>1;
            i++;
        }
        reverse(temp.begin(),temp.end());
        for(int i=0;i<32;i++)
            cout<<temp[i];
        for(int i=0;i<32;i++){
            if(count==0){
                break;
            }
            if(temp[i]==1){
                temp[i]=2;
                count--;
            }
        }
        if(count>0){
            for(int i=31;i>=0;i--){
                if(count==0){
                    break;
                }
                if(temp[i]!=2){
                    temp[i]=2;
                    count--;
                }
            }
        }
        int answer=0;
        for(int i=31;i>=0;i--){
            if(temp[i]==2){
                answer=answer+pow(2,31-i);
            }
        }
        return answer;
        
    }
};