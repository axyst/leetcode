// if the optimal section is narrower than current one, at least one of the edges must be taller than corresponding current edge
class Solution {
public:
    int maxArea(vector<int> &height) {
        try {
            int left = 0, right = static_cast<int>(height.size() - 1);
            int ret = 0;
            while(left < right) {
                ret = max(ret, (right - left) * min(height[left], height[right]));
                if(height[left] < height[right]) ++left;
                else --right;
            }
            return ret;
        }
        catch (const exception &exc) {
            cout << exc.what() << endl;
        }
    }
};