class Solution {
public:
    int numWaterBottles(int numBottle, int numExchange) {
        int answer=0;
        while(numBottle>=numExchange){
            int a=numBottle%numExchange;
            int b=numBottle/numExchange;
            answer=answer+ (b*numExchange);
            numBottle=a+b;
        }
        answer=answer+numBottle;
        return answer;
    }
};