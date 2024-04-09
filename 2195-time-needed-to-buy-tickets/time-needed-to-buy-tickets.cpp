class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        if(tickets[k]==1){
            return k+1;
        }
        int answer=0;
        int count=0;
        for(int i=0;i<tickets.size();i++){
            if(tickets[i]<tickets[k]){
                answer=answer+tickets[i];
                count++;
            }
        }
        // number greater then tickets[i]after i
        int count2=0;
        for(int i=k+1;i<tickets.size();i++){
            if(tickets[i]>=tickets[k]){
                count2++;
            }
        }
        count=tickets.size()-count;
        answer=answer+(count*tickets[k]-count2);
        return answer;
    }
};