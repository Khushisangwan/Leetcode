class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long sq = 1LL * mid * mid;

            if (sq > x) {
                r = mid - 1;
            }
            else if (sq == x) {
                return mid;
            }
            else {
                l = mid + 1;
            }
        }

        return r;
    }
};