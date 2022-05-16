class Solution
{
private:
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ret = 0;
        for (int i = 0; i < 32; i++)
        {
            uint32_t cur = (n >> i) & 1;
            if (cur) ret |= (1 << (31 - i)); // 当前位左移(31-i)为对称位
        }
        return ret;
    }
    /*
    uint32_t reverseBits(uint32_t n)
    {
        const uint32_t M1 = 0x55555555;  // 0101 0101 0101 0101 0101 0101 0101 0101
        const uint32_t M2 = 0x33333333;  // 0011 0011 0011 0011 0011 0011 0011 0011
        const uint32_t M4 = 0x0f0f0f0f;  // 0000 1111 0000 1111 0000 1111 0000 1111
        const uint32_t M8 = 0x00ff00ff;  // 0000 0000 1111 1111 0000 0000 1111 1111
        n = n >> 1 & M1 | (n & M1) << 1; // 奇数位移到偶数位上，偶数位移到奇数位上
        n = n >> 2 & M2 | (n & M2) << 2;
        n = n >> 4 & M4 | (n & M4) << 4;
        n = n >> 8 & M8 | (n & M8) << 8;
        return n >> 16 | n << 16; // 将其均分成左右两部分，对每部分递归执行翻转操作，然后将左半部分拼在右半部分的后面
    }
    */
};
