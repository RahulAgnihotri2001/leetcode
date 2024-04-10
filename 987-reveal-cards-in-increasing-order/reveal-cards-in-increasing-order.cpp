class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& desk) {
        sort(desk.begin(),desk.end());
        queue<int> qu;
        for(int i=0;i<desk.size();i++){
            qu.push(i);
        }
        vector<int> answer;
        while(!qu.empty()){
            answer.push_back(qu.front());
            qu.pop();
            if(qu.empty()){
                break;
            }
            int a=qu.front();
            qu.pop();
            qu.push(a);
        }
        vector<int> answer2(desk.size());
        for(int i=0;i<desk.size();i++){
            answer2[answer[i]]=desk[i];
        }
        return answer2;
    }
};