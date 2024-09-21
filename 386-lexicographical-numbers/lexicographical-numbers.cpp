class Solution {
public:

    void func(int i,vector<int> &answer,int &n){
        if(i<=n){
            answer.push_back(i);
            for(int j=0;j<=9;j++){
                func(i*10+j,answer,n);
            }
            return;
        }
        else{
            return;
        }
    }



    vector<int> lexicalOrder(int n) {
        // Recursive approch 
        vector<int> answer;
        for(int i=1;i<=9;i++){
            func(i,answer,n);
        }
        return answer;
    }
};