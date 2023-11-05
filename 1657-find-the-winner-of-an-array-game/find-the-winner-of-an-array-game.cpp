class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        // check right mein larger after how much
        stack<int> st;
        vector<int> vec;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty()){
                vec.push_back(arr.size()-i-1);
                st.push(i);
            }
            else{
                //int flag=0;
                while(!st.empty()&& arr[st.top()]<arr[i]){
                    st.pop();
                    //flag=1;
                }
                if(st.empty()){
                    vec.push_back(arr.size()-i-1);
                    st.push(i);
                }
                else{
                    vec.push_back(st.top()-i-1);
                    st.push(i);
                }
            }   
        }
        reverse(vec.begin(),vec.end());
        int ma=arr[0];
        for(int i=1;i<vec.size();i++){
            if(arr[i]>ma){
                vec[i]++;
                ma=arr[i];
            }
        }
        for(int i=0;i<vec.size();i++){
            if(vec[i]>=k){
                return arr[i];
            }
        }
        ma=0;
        for(int i=1;i<arr.size();i++){
            if(arr[ma]<arr[i]){
                ma=i;
            }
        }
        return arr[ma];
        
    }
};