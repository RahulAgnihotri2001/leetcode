class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int answer=0;
        sort(people.begin(),people.end());
        int start=0 , end=people.size()-1;
        while(start<=end){
            if(people[start]+people[end]<=limit){
                answer++;
                start++;
                end--;
            }
            else{
                answer++;
                end--;
            }
        }
        return answer;
    }
};