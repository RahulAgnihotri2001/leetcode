class CustomStack {
public:

    vector<int> sta;
    int maxsize=0;

    CustomStack(int maxSize) {
        maxsize=maxSize;
    }
    
    void push(int x) {
        if(sta.size()<maxsize){
            sta.push_back(x);
        }
    }
    
    int pop() {
        int temp=-1;
        if(sta.size()>0){
            temp=sta[sta.size()-1];
            sta.pop_back();
        }
        return temp;
    }
    
    void increment(int k, int val) {
        int i=0;
        while(i<sta.size() && k>0){
            sta[i]=sta[i]+val;
            i++;
            k--;
        }

    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */