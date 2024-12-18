class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        vector<int> discount;
        for(int i=prices.size()-1;i>=0;i--){
            while(!st.empty() && st.top()>prices[i]){
                st.pop();
            }
            if(st.empty()){
                discount.push_back(0);
                st.push(prices[i]);
                continue;
            }
            else{
                discount.push_back(st.top());
                st.push(prices[i]);
            }
        }
        reverse(discount.begin(),discount.end());
        for(int i=0;i<prices.size();i++){
            prices[i]=prices[i]-discount[i];
        }
        return prices;
    }
};