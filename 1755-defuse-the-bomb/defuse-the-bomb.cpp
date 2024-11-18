class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> answer;
        if(k>0){
            for(int i=0;i<code.size();i++){
                int x=0;
                for(int j=1;j<=k;j++){
                    x=x+code[(i+j)%code.size()];
                }
                answer.push_back(x);
            }
        }
        else if(k<0){
            // cout<<"hello";
            for(int i=0;i<code.size();i++){
                int x=0;
                for(int j=1;j<=abs(k);j++){
                    int y=(i-j);
                    if(y<0){
                        y=y+code.size();
                    }
                    x=x+code[y];
                }
                cout<<"\n";
                answer.push_back(x);
            }
        }
        else{
            for(int i=0;i<code.size();i++){
                answer.push_back(0);
            }
        }
        return answer;
    }
};