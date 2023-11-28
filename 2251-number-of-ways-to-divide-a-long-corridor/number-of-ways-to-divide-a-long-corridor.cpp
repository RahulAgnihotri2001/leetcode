class Solution {
public:
    int numberOfWays(string cor) {
        int count=0;
        for(int i=0;i<cor.length();i++){
            if(cor[i]=='S'){
                count++;
            }
        }
        if(count==2){
            return 1;
        }
        if(count%2!=0 || count==0){
            return 0;
        }
        long  answer=1;
        long index=0;
         count=0;
        while(index<cor.length()){
            if(cor[index]=='S'){
                count++;
            }
            if(count==2){
                break;
            }
            index++;
        }
        long temp=index;
        index++;
        while(index<cor.length()){
            while(index<cor.length() && cor[index]!='S'){
                index++;
            }
            if(index>=cor.length()){
                break;
            }
           // cout<<index<<" "<<temp<<endl;
            answer=(answer*(index-temp))%1000000007;
            index++;
            while(cor[index]!='S'){
                index++;
            }
            temp=index;
            index++;
        }
        return answer%1000000007;

    }
};