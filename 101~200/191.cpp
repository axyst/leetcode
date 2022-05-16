class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        for (int i = 0; i < 32; i++)
        {
            uint32_t cur = (n >> i) & 1;
            if (cur) ret += 1;
        }
        return ret;
    }
};