// 建一个最大堆，一个最小堆
class MedianFinder
{
    priority_queue<int> left_heap;
    priority_queue<int, vector<int>, greater<int> > right_heap;
public:
    void addNum(int num)
    {
        left_heap.push(num);
        right_heap.push(left_heap.top());
        left_heap.pop();
        if (left_heap.size() < right_heap.size())
        {
            left_heap.push(right_heap.top());
            right_heap.pop();
        }
    }
    double findMedian()
    {
        if (left_heap.size() != right_heap.size())
            return left_heap.top();
        return ((left_heap.top() + right_heap.top()) * 0.5);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */