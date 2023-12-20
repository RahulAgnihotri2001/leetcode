class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        // find 2 smallest numbers 
        // i need a min heap
        if(prices.size()==1){
            return money;
        }
        priority_queue<int> pq;
        for(int i=0;i<prices.size();i++){
            if(pq.size()<2){
                pq.push(prices[i]);
            }
            else{
                if(prices[i]<pq.top()){
                    pq.pop();
                    pq.push(prices[i]);
                }
            }
        }
        int a=pq.top();
        pq.pop();
        a=a+pq.top();
        if(a>money){
            return money;
        }
        return money-a;

    }
};