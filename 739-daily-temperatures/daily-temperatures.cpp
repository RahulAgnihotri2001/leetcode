class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>>st;
        //reverse(temp.begin(),temp.end());
        vector<int> answer;
        for(int i=temp.size()-1;i>=0;i--){
            if(st.empty()){
                st.push({temp[i],0});
                answer.push_back(0);
            }
            else{
                int p=0;
                while(!st.empty() && st.top().first<=temp[i]){
                    p=p+st.top().second;
                    st.pop();
                }
                if(st.empty()){
                    answer.push_back(0);
                    st.push({temp[i],0});
                }
                else{
                    answer.push_back(p+1);
                    st.push({temp[i],p+1});
                }
            }
        }
        reverse(answer.begin(),answer.end());
        return answer;

    }
};