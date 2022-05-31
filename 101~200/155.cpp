class MinStack
{
    vector<long> *st;
    int sz;
    int mn;

public:
    MinStack()
    {
        st = new vector<long>;
        sz = 0;
        mn = -1;
    }
    ~MinStack()
    {
        delete st;
    }

    void push(int val)
    {
        if (!sz)
        {
            st->push_back(0);
            mn = val;
        }
        else
        {
            long diff = (long)val - (long)mn;
            st->push_back(diff);
            mn = min(mn, val);
        }
        sz++;
    }

    void pop()
    {
        long diff = st->at(--sz);
        st->pop_back();
        if (diff < 0)
            mn -= diff;
    }

    int top()
    {
        long ret = (st->at(sz - 1) > 0 ? st->at(sz - 1) : 0) + mn;
        return (int)ret;
    }

    int getMin()
    {
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