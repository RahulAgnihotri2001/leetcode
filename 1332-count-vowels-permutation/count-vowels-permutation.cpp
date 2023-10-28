int N=1000000007;
class Solution {
public:
    int fun(int index,char ch,int n,map<pair<int,char>,int> &mp){
        if(index==n-1){
            return 1;
        }
        if(mp.find({index,ch})!=mp.end()){
            return mp[{index,ch}];
        }
        if(ch=='a'){
            mp[{index,ch}]=fun(index+1,'e',n,mp);
            return mp[{index,ch}];
        }
        else if(ch=='e'){
            int x=fun(index+1,'a',n,mp);
            x=(x+fun(index+1,'i',n,mp))%N;
            mp[{index,ch}]= x;
            return mp[{index,ch}];
        }
        else if(ch=='o'){
            int x=fun(index+1,'i',n,mp);
            x=(x+fun(index+1,'u',n,mp))%N;
            mp[{index,ch}]=x;
            return x;
        }
        else if(ch=='u'){
            int x=fun(index+1,'a',n,mp);
            mp[{index,ch}]=x;
            return x;
        }
        else{
            int x=fun(index+1,'a',n,mp);
             x=(x+fun(index+1,'e',n,mp))%N;
              x=(x+fun(index+1,'o',n,mp))%N;
               x=(x+fun(index+1,'u',n,mp))%N;
               mp[{index,ch}]=x;
               return x;
        }

    }
    int countVowelPermutation(int n) {
        int index=0;
        int answer=0;
        map<pair<int,char>,int> mp;
        vector<char> vec{'a','e','i','o','u'};
        for(int i=0;i<vec.size();i++){
            answer=(answer+fun(index,vec[i],n,mp))%N;
        }
        return answer;
    }
};