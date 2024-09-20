class Solution {
public:
    // A very classic example of MOM   
    vector<int> func(int start,int end,string expression){
        if(start==end || end-start==1){
            vector<int> temp;
            temp.push_back(stoi(expression.substr(start,end-start+1)));
            return temp;
        }
        vector<int> temp;
        vector<int> right;
        vector<int> left;
        for(int k=start+1;k<end;k++){
            if(expression[k]=='+'){
                left=func(start,k-1,expression);
                right=func(k+1,end,expression);
                for(int i=0;i<left.size();i++){
                    for(int j=0;j<right.size();j++){
                        temp.push_back(left[i]+right[j]);
                    }
                }
            }
            else if(expression[k]=='-'){
                left=func(start,k-1,expression);
                right=func(k+1,end,expression);
                for(int i=0;i<left.size();i++){
                    for(int j=0;j<right.size();j++){
                        temp.push_back(left[i]-right[j]);
                    }
                }
            }
            else if(expression[k]=='*'){
                left=func(start,k-1,expression);
                right=func(k+1,end,expression);
                for(int i=0;i<left.size();i++){
                    for(int j=0;j<right.size();j++){
                        temp.push_back(left[i]*right[j]);
                    }
                }
            }
        }
        return temp;
    }


    vector<int> diffWaysToCompute(string expression) {
        vector<int> answer=func(0,expression.length()-1,expression);
        return answer;
    }
};