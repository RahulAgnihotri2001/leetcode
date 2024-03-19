class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // get the count of the heighest occuring number
        vector<int> vec(26,0);
        for(int i=0;i<tasks.size();i++){
            vec[tasks[i]-'A']++;
        }
        int max_occur=0;
        for(int i=0;i<vec.size();i++){
            max_occur=max(max_occur,vec[i]);
        }
        // get count of max occur
        int count_max_occur=0;
        for(int i=0;i<vec.size();i++){
            if(vec[i]==max_occur){
                count_max_occur++;
            }
        }
        int answer=((n+1)*max_occur)-n;
        // spaceleft = n*max_occure
        if(count_max_occur-1>n){
            answer=answer+(count_max_occur-1-n)*max_occur + n;
        }
        else
            answer=answer+(count_max_occur-1);
        int spaceleft=answer-(count_max_occur)*max_occur;
        if(spaceleft>=tasks.size()-(count_max_occur)*max_occur){
            return answer;
        }
        return answer+((tasks.size()-(count_max_occur)*max_occur)-spaceleft);

    }
};