class MinStack {
    vector<int>* st;
    int sz;
    int mn;
public:
    MinStack() {
        st=new vector<int>;
        sz=0;
        mn = INT_MAX;
    }
    
    void push(int val) {
        if(!sz)
        {
            st.push_back(0);
            mn=val;
        }
        else
        {
            int diff = val-mn;
            st.push_back(diff);
            mn=min(mn,val);
        }
        sz++;
    }
    
    void pop() {
        st.pop_back();
        sz--;
    }
    
    int top() {
        return st[sz-1]+mn;
    }
    
    int getMin() {
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */