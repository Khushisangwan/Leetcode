class Solution {
public:
    int guessNumber(int n) {
        int beg = 1, end = n;

        while (beg <= end) {
            int mid = beg + (end - beg) / 2;

            int res = guess(mid);

            if (res == 0)
                return mid;
            else if (res == 1)
                beg = mid + 1;
            else
                end = mid - 1;
        }

        return -1;
    }
};