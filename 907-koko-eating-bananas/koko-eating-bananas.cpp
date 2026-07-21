class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;

        for (int pile : piles) {
            right = max(right, pile);
        }

        while (left < right) {
            int mid = left + (right - left) / 2;

            long long hours = 0;

            for (int pile : piles) {
                hours += (pile + mid - 1) / mid;
            }

            if (hours <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};