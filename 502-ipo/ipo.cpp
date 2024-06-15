class Solution {
public:

    static bool fun(vector<int> &v1 , vector<int> &v2){
        if(v1[1]!=v2[1])
        return v1[1]<v2[1];
        else
        return v1[0]<v2[0];
    }    

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> vec;
        for(int i=0;i<profits.size();i++){
            vector<int> temp;
            temp.push_back(profits[i]);
            temp.push_back(capital[i]);
            vec.push_back(temp);
        }
        sort(vec.begin(),vec.end(),fun);
        int ans=0;
        int count=0;
        int index=0;
        priority_queue<vector<int> > pq;
        while(count<vec.size() && count!=k){
            while(index<vec.size() && vec[index][1]<=w){
                pq.push(vec[index]);
                index++;
            }
            if(!pq.empty()){
            ans=ans+pq.top()[0];
            w=w+pq.top()[0];
            pq.pop();
            count++;
            }
            else{
                break;
            }
        }
        return w;

    }
};