class Solution {
public:
    int maximumSwap(int num) {
        //  find largest on left
        if(num<10){
            return num;
        }
        // should store number in an array
        vector<int> temp;
        int n=num;
        while(n){
            temp.push_back(n%10);
            n=n/10;
        }
        vector<int> temp2;
        for(int i=0;i<temp.size();i++){
            temp2.push_back(i);
        }
        priority_queue<pair<int,int>> pq;
        pq.push({temp[0],0});
        for(int i=1;i<temp.size();i++){
            while(!pq.empty() && pq.top().first <= temp[i]){
                if(pq.top().first != temp[i]){
                    pq.pop();
                }
                else{
                    break;
                }
            }
            if(pq.empty())
                pq.push({temp[i],i});
            if(pq.top().first != temp[i])
                temp2[i]=pq.top().second;
        }
        for(int i=temp.size()-1;i>=0;i--){
            if(temp2[i]!=i){
                swap(temp[i],temp[temp2[i]]);
                break;
            }
        }
        int answer=temp[temp.size()-1];
        for(int i=temp.size()-2;i>=0;i--){
            answer=answer*10+temp[i];
        }
        return answer;
    }
};