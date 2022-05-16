// 手写：https://leetcode-cn.com/problems/lru-cache/solution/lruhuan-cun-ji-zhi-by-leetcode-solution/
typedef pair<int, int> pii;
class LRUCache
{
    unordered_map<int, list<pii>::iterator> cache;
    int cap;
    list<pii> lis;
public:
    LRUCache(int capacity)
    {
        cap = capacity;
        cache.clear();
        lis.clear();
    }
    int get(int key)
    {
        if (cache.find(key) == cache.end()) return -1;
        auto node = cache[key];
        int val = node->second;
        lis.erase(node);
        lis.emplace_front(make_pair(key, val));
        cache[key] = lis.begin();
        return val;
    }
    void put(int key, int value)
    {
        if (cache.find(key) == cache.end())
        {
            if (lis.size() >= cap)
            {
                auto node = lis.end(); node--;
                cache.erase(node->first);
                lis.pop_back();
            }
        }
        else
        {
            auto node = cache[key];
            lis.erase(node);
        }
        lis.emplace_front(make_pair(key, value));
        cache[key] = lis.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 The functions get and put must each run in O(1) average time complexity.

 */