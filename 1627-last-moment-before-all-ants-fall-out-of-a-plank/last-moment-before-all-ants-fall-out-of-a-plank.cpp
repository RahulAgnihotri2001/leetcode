class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        //find max in left;
        int x=0;
        if(left.size()!=0){
            x=left[0];
            for(int i=1;i<left.size();i++){
                x=max(x,left[i]);
            }
        }
        //find min in right;
        int y=n;
        if(right.size()>0){
            y=right[0];
            for(int i=1;i<right.size();i++){
                y=min(y,right[i]);
            }
        }
        return max(n-y,x);
    }
};